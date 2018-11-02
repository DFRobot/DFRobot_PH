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
    DFRobot_PH();
    ~DFRobot_PH();
    void    calibration(float voltage, float temperature,char* cmd);  //calibration by Serial CMD
    void    calibration(float voltage, float temperature);
    float   readPH(float voltage, float temperature); // voltage to pH value, with temperature compensation
    void    begin();   //initialization

private:
    float  _phValue;
    float  _acidVoltage;
    float  _neutralVoltage;
    float  _voltage;
    float  _temperature;

    char   _cmdReceivedBuffer[ReceivedBufferLength];  //store the Serial CMD
    byte   _cmdReceivedBufferIndex;

private:
    boolean cmdSerialDataAvailable();
    void    phCalibration(byte mode); // calibration process, wirte key parameters to EEPROM
    byte    cmdParse(const char* cmd);
    byte    cmdParse();
};

#endif
