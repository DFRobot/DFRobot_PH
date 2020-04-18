/*
 * file DFRobot_PH.h * @ https://github.com/DFRobot/DFRobot_PH
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

#ifndef _DFROBOT_PH_H_
#define _DFROBOT_PH_H_

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#define ReceivedBufferLength 10  //length of the Serial CMD buffer

class DFRobot_PH
{
public:
    // Construtors
    DFRobot_PH();
    DFRobot_PH(int phPin);
    
    // Destructors
    ~DFRobot_PH();
    
    // Initialization
    void    begin();   
    
    // Calibration by Serial CMD
    void    calibration(float voltage, float temperature, char* cmd);  
    void    calibration(float voltage, float temperature);
    
    // Voltage to pH value, with temperature compensation
    float   readPH(float voltage, float temperature); 

private:
    int _pin;
    int _address;
    float  _phValue;
    float  _acidVoltage;
    float  _neutralVoltage;
    float  _voltage;
    float  _temperature;

    // Store the Serial CMD
    char   _cmdReceivedBuffer[ReceivedBufferLength];  
    byte   _cmdReceivedBufferIndex;

private:
    // Calibration process, wirte key parameters to EEPROM
    void    phCalibration(byte mode); 
    
    boolean cmdSerialDataAvailable();
        
    byte    cmdParse();
    byte    cmdParse(const char* cmd);
};

#endif
