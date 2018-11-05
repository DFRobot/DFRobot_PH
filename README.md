## DFRobot_PH.py Library for Raspberry pi
---------------------------------------------------------
This is the sample code for Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2
## Table of Contents

* [Methods](#methods)
<snippet>
<content>

## Methods

```C++

/*
 * @brief Init The Analog pH Sensor
 */
void begin();

/*
 * @brief Convert voltage to PH with temperature compensation
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
## Credits

Written by Jiawei Zhang, 2018. (Welcome to our [website](https://www.dfrobot.com/))
