## DFRobot_PH Library
---------------------------------------------------------
This is the sample code for Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2

WARNING: There is no temperature compensation implemented in this library.
         Although you can provide the temperature it is not used.

## Table of Contents

* [Methods](#methods)
* [Compatibility](#Compatibility)
* [History](#history)
* [Credits](#credits)
<snippet>
<content>

## Methods

```C++
/*
 * @brief The new optional constructor to allow multiple pH sensors
 *
 * @param phPin: The pin of the pH sensor i.e. A0
 */
DFRobot_PH(int phPin);

/*
 * @brief Init The Analog pH Sensor
 */
void begin();

/*
 * @brief Convert voltage to PH
 *
 * @param voltage     : Voltage value
 *        temperature : Ambient temperature
 *
 * @return The PH value
 */
float readPH(float voltage, float temperature);

/*
 * @brief Calibrate the calibration data
 *
 * @param voltage     : Voltage value
 *        temperature : Ambient temperature
 *        cmd         : enterph -> enter the PH calibration mode
 *                      calph   -> calibrate with the standard buffer solution, two buffer solutions(4.0 and 7.0) will be automaticlly recognized
 *                      exitph  -> save the calibrated parameters and exit from PH calibration mode
 */
void calibration(float voltage, float temperature, char* cmd);

```

## Compatibility

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno  |      √       |             |            | 
Leonardo  |      √       |             |            | 
Meag2560 |      √       |             |            | 

## History

- date 2018-11-6
- version V1.0
    - Inital version
- date 2020-04-18
- version V1.1
    - Update to allow multiple pH sensors each with their own calibration

## Credits

Written by Jiawei Zhang(Welcome to our [website](https://www.dfrobot.com/))
