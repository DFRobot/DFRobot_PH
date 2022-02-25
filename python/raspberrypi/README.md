## DFRobot_PH

* [中文版](./README_CN.md)

This is the sample code for Gravity: Analog pH Sensor / Meter Kit V2, SKU:SEN0161-V2

![产品效果图](../../resources/images/SEN0161-V2.png)

## Product Link ([https://www.dfrobot.com/product-1782.html](https://www.dfrobot.com/product-1782.html))
    SKU: SEN0161-V2

## Table of Contents

  * [Summary](#summary)
  * [Installation](#installation)
  * [Methods](#methods)
  * [Compatibility](#compatibility)
  * [History](#history)
  * [Credits](#credits)

## Summary

Analog pH meter V2 is specifically designed to measure the pH of the solution and reflect the acidity or alkalinity. DFRobot ph sensor is commonly used in various applications such as aquaponics, aquaculture, and environmental water testing.


## Installation
1. To use this library, first download the library file<br>
```python
sudo git clone https://github.com/DFRobot/DFRobot_PH
```
2. Open and run the routine. To execute a routine demo_x.py, enter python demo_x.py in the command line. For example, to execute the demo_read_aht20.py routine, you need to enter :<br>

```python
python demo_PH_read.py 
or
python2 demo_PH_read.py 
```

## Methods

```python
  '''!
    @brief   Initialization The Analog pH Sensor.
  '''
  def begin(self):
		
  '''!
    @brief   Convert voltage to PH with temperature compensation.
    @note voltage to pH value, with temperature compensation
    @param voltage       Voltage value
    @param temperature   Ambient temperature
    @return  The PH value
  '''
  def read_PH(self,voltage,temperature):

  '''!
    @brief   Calibrate the calibration data.
    @param voltage       Voltage value
  '''
  def calibration(self,voltage):

  '''!
    @brief   Reset the calibration data to default value.
  '''	
  def reset(self):

```
## Compatibility

| 主板         | 通过 | 未通过 | 未测试 | 备注 |
| ------------ | :--: | :----: | :----: | :--: |
| RaspberryPi2 |      |        |   √    |      |
| RaspberryPi3 |      |        |   √    |      |
| RaspberryPi4 |  √   |        |        |      |

* Python 版本

| Python  | 通过 | 未通过 | 未测试 | 备注 |
| ------- | :--: | :----: | :----: | ---- |
| Python2 |  √   |        |        |      |
| Python3 |      |        |   √    |      |
## History

- 2018/11/06 - Version 1.0.0 released.

## Credits

Written by Jiawei Zhang(jiawei.zhang@dfrobot.com), 2018. (Welcome to our [website](https://www.dfrobot.com/))
