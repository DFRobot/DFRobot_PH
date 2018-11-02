## DFRobot_PH.py Library for Raspberry pi
---------------------------------------------------------
This is the sample code for Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2
## Table of Contents

* [Installation](#installation)
* [Methods](#methods)
<snippet>
<content>

## Installation
The Analog pH Sensor should work with ADS1115
(https://github.com/DFRobot/DFRobot_ADS1115/tree/master/RaspberryPi/Python) 

Run the program:

```cpp

$> python DFRobot_ADS1115.py

$> python DFRobot_PH.py

```
## Methods

```C++

/*
 * @brief Init The Analog pH Sensor
 */
def begin(self);

/*
 * @brief Convert voltage to PH with temperature compensation
 */
def readPH(self,voltage,temperature);

/*
 * @brief Calibrate the calibration data
 */
def calibration(self,voltage,temperature);

/*
 * @brief Reset the calibration data to default value
 */
def reset(self);

```
## Credits

Written by Jiawei Zhang, 2018. (Welcome to our [website](https://www.dfrobot.com/))
