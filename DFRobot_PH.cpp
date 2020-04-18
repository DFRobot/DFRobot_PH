/*
 * file DFRobot_PH.cpp * @ https://github.com/DFRobot/DFRobot_PH
 *
 * Arduino library for Gravity: Analog pH Sensor / Meter Kit V2, SKU: SEN0161-V2
 *
 * Copyright   [DFRobot](http://www.dfrobot.com), 2018
 * Copyright   GNU Lesser General Public License
 *
 * version  V1.0
 * date  2018-04
 * 
 * version  V1.1
 * date  2020-04
 * Changes the memory addressing to allow multiple PH sensors
 */

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "DFRobot_PH.h"
#include <EEPROM.h>

#define EEPROM_write(address, value) {int i = 0; byte *pp = (byte*)&(value);for(; i < sizeof(value); i++) EEPROM.write(address+i, pp[i]);}
#define EEPROM_read(address, value)  {int i = 0; byte *pp = (byte*)&(value);for(; i < sizeof(value); i++) pp[i]=EEPROM.read(address+i);}

// The start address of the pH calibration parameters stored in the EEPROM
#define PHVALUEADDR 0    

// Default construtor to ensure backwards compatibility
DFRobot_PH::DFRobot_PH()
{
    // As no pin was provided we will use the data for pin A0
    this->_pin            = A0;

    // Set the address
    // For each PH sensor we need to store 2 floats (pH 4.0 and pH 7.0)
    // This will be 8byte per sensor and the largest arduino has 12 analogue ports
    // So let's start at address 0 and go up by 8b for each analogue port. This will use upto 96b 
    // For the EC library we will start after PH addresses
    this->_address        = PHVALUEADDR + (sizeof(float) * 2 *  this->_pin);

    // Buffer solution 4.0 at 25C
    this->_acidVoltage    = 2032.44;    

    // Buffer solution 7.0 at 25C
    this->_neutralVoltage = 1500.0;     

    // Initialise the rest of the values with an initial starting value    
    this->_voltage        = 1500.0;
    this->_temperature    = 25.0;
    this->_phValue        = 7.0;
}

// Updated construtor to allow multiple pH sensors
DFRobot_PH::DFRobot_PH(int phPin)
{
    // Set the pin to the supplied value
    this->_pin            = phPin;

    // Set the address
    // For each PH sensor we need to store 2 floats (pH 4.0 and pH 7.0)
    // This will be 8byte per sensor and the largest arduino has 12 analogue ports
    // So let's start at address 0 and go up by 8b for each analogue port. This will use upto 96b 
    // For the EC library we will start after PH addresses
    this->_address        = PHVALUEADDR + (sizeof(float) * 2 *  this->_pin);

    // Buffer solution 4.0 at 25C
    this->_acidVoltage    = 2032.44;    

    // Buffer solution 7.0 at 25C
    this->_neutralVoltage = 1500.0;     

    // Initialise the rest of the values with an initial starting value    
    this->_voltage        = 1500.0;
    this->_temperature    = 25.0;
    this->_phValue        = 7.0;
}

// Default destructor
DFRobot_PH::~DFRobot_PH()
{
}

// Initialiser
void DFRobot_PH::begin()
{
    // Load the neutral (pH = 7.0) voltage of the pH board from the EEPROM
    EEPROM_read(this->_address, this->_neutralVoltage);  
    Serial.print("_neutralVoltage:");
    Serial.println(this->_neutralVoltage);

    // If the values are all 255 then  write a default value in
    if(EEPROM.read(this->_address)==0xFF && EEPROM.read(this->_address+1)==0xFF && EEPROM.read(this->_address+2)==0xFF && EEPROM.read(this->_address+3)==0xFF){
        // new EEPROM, write typical voltage for pH = 7.0
        this->_neutralVoltage = 1500.0;  
        EEPROM_write(this->_address, this->_neutralVoltage);
    }

    // Load the acid (pH = 4.0) voltage of the pH board from the EEPROM
    EEPROM_read(this->_address+4, this->_acidVoltage);
    Serial.print("_acidVoltage:");
    Serial.println(this->_acidVoltage);

    // If the values are all 255 then  write a default value in
    if(EEPROM.read(this->_address+4)==0xFF && EEPROM.read(this->_address+5)==0xFF && EEPROM.read(this->_address+6)==0xFF && EEPROM.read(this->_address+7)==0xFF){
         // new EEPROM, write typical voltage for pH = 4.0
        this->_acidVoltage = 2032.44;
        EEPROM_write(this->_address+4, this->_acidVoltage);
    }
}

// Function to read the pH
float DFRobot_PH::readPH(float voltage, float temperature)
{
    // From the two point calibration: (_neutralVoltage, 7.0), (_acidVoltage, 4.0)
    float slope = (7.0 - 4.0)/((this->_neutralVoltage - 1500.0) / 3.0 - (this->_acidVoltage - 1500.0) / 3.0);  
    float intercept =  7.0 - slope*(this->_neutralVoltage - 1500.0) / 3.0;
    
    // Linear response y = k*x + b
    this->_phValue = slope * (voltage - 1500.0) / 3.0 + intercept;  
    
    return _phValue;
}


void DFRobot_PH::calibration(float voltage, float temperature, char* cmd)
{
    this->_voltage = voltage;
    this->_temperature = temperature;
    strupr(cmd);

    // If received Serial CMD from the serial monitor, enter into the calibration mode
    phCalibration(cmdParse(cmd));  
}

void DFRobot_PH::calibration(float voltage, float temperature)
{
    this->_voltage = voltage;
    this->_temperature = temperature;

    // If received Serial CMD from the serial monitor, enter into the calibration mode
    if(cmdSerialDataAvailable() > 0){
        phCalibration(cmdParse());  
    }
}

boolean DFRobot_PH::cmdSerialDataAvailable()
{
    char cmdReceivedChar;
    static unsigned long cmdReceivedTimeOut = millis();
    while(Serial.available()>0){
        if(millis() - cmdReceivedTimeOut > 500U){
            this->_cmdReceivedBufferIndex = 0;
            memset(this->_cmdReceivedBuffer,0,(ReceivedBufferLength));
        }
        cmdReceivedTimeOut = millis();
        cmdReceivedChar = Serial.read();
        if (cmdReceivedChar == '\n' || this->_cmdReceivedBufferIndex==ReceivedBufferLength-1){
            this->_cmdReceivedBufferIndex = 0;
            strupr(this->_cmdReceivedBuffer);
            return true;
        }else{
            this->_cmdReceivedBuffer[this->_cmdReceivedBufferIndex] = cmdReceivedChar;
            this->_cmdReceivedBufferIndex++;
        }
    }
    return false;
}

byte DFRobot_PH::cmdParse(const char* cmd)
{
    byte modeIndex = 0;
    if(strstr(cmd, "ENTERPH")      != NULL){
        modeIndex = 1;
    }else if(strstr(cmd, "EXITPH") != NULL){
        modeIndex = 3;
    }else if(strstr(cmd, "CALPH")  != NULL){
        modeIndex = 2;
    }
    return modeIndex;
}

byte DFRobot_PH::cmdParse()
{
    byte modeIndex = 0;
    if(strstr(this->_cmdReceivedBuffer, "ENTERPH")      != NULL){
        modeIndex = 1;
    }else if(strstr(this->_cmdReceivedBuffer, "CALPH")  != NULL){
        modeIndex = 2;
    }else if(strstr(this->_cmdReceivedBuffer, "EXITPH") != NULL){
        modeIndex = 3;
    }
    return modeIndex;
}

void DFRobot_PH::phCalibration(byte mode)
{
    char *receivedBufferPtr;
    static boolean phCalibrationFinish  = 0;
    static boolean enterCalibrationFlag = 0;
    switch(mode){
        case 0:
        if(enterCalibrationFlag){
            Serial.println(F(">>>Command Error<<<"));
        }
        break;

        case 1:
        enterCalibrationFlag = 1;
        phCalibrationFinish  = 0;
        Serial.println();
        Serial.println(F(">>>Enter PH Calibration Mode<<<"));
        Serial.println(F(">>>Please put the probe into the 4.0 or 7.0 standard buffer solution<<<"));
        Serial.println();
        break;

        case 2:
        if(enterCalibrationFlag){
            if((this->_voltage>1322)&&(this->_voltage<1678)){        // buffer solution:7.0
                Serial.println();
                Serial.print(F(">>>Buffer Solution:7.0"));
                this->_neutralVoltage =  this->_voltage;
                Serial.println(F(",Send EXITPH to Save and Exit<<<"));
                Serial.println();
                phCalibrationFinish = 1;
            }else if((this->_voltage>1854)&&(this->_voltage<2210)){  //buffer solution:4.0
                Serial.println();
                Serial.print(F(">>>Buffer Solution:4.0"));
                this->_acidVoltage =  this->_voltage;
                Serial.println(F(",Send EXITPH to Save and Exit<<<")); 
                Serial.println();
                phCalibrationFinish = 1;
            }else{
                Serial.println();
                Serial.print(F(">>>Buffer Solution Error Try Again<<<"));
                Serial.println();                                    // not buffer solution or faulty operation
                phCalibrationFinish = 0;
            }
        }
        break;

        case 3:
        if(enterCalibrationFlag){
            Serial.println();
            if(phCalibrationFinish){
                if((this->_voltage>1322)&&(this->_voltage<1678)){
                    EEPROM_write(this->_address, this->_neutralVoltage);
                }else if((this->_voltage>1854)&&(this->_voltage<2210)){
                    EEPROM_write(this->_address+4, this->_acidVoltage);
                }
                Serial.print(F(">>>Calibration Successful"));
            }else{
                Serial.print(F(">>>Calibration Failed"));
            }
            Serial.println(F(",Exit PH Calibration Mode<<<"));
            Serial.println();
            phCalibrationFinish  = 0;
            enterCalibrationFlag = 0;
        }
        break;
    }
}
