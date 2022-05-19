# DFRobot_PH

* [English Version](./README.md)

这是 Gravity 的示例代码：模拟 pH 传感器/仪表套件 V2，SKU：SEN0161-V2

![产品效果图](./resources/images/SEN0161-V2.png)


## 产品链接（[https://www.dfrobot.com.cn/goods-1828.html](https://www.dfrobot.com.cn/goods-1828.html)）
    SKU: SEN0161-V2
   
## 目录

* [概述](#概述)
* [库安装](#库安装)
* [方法](#方法)
* [兼容性](#兼容性)
* [历史](#历史)
* [创作者](#创作者)

## 概述

模拟pH计V2专门用于测量溶液的pH，衡量溶液的酸碱程度，常用于鱼菜共生、水产养殖、环境水检测等领域。

## 库安装

这里有2种安装方法：
1. 使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。
2. 直接在Arduino软件库管理中搜索下载 DFRobot_AHT20 库 <br>
在运行此库的demo之前，你需要下载关联库: https://github.com/DFRobot/DFRobot_EC

## 方法

```C++
  /**
   * @fn calibration
   * @brief 使用校准参数校准PH计
   *
   * @param voltage     : 电压值
   * @param temperature : 环境温度值
   * @param cmd         : enterph -> 进入PH计校准模式
   * @n                   calph   -> 用标准缓冲液校准，自动识别两种缓冲液（4.0和7.0）
   * @n                   exitph  -> 保存校准参数并退出 PH 校准模式
   */
  void    calibration(float voltage, float temperature,char* cmd); 
  void    calibration(float voltage, float temperature);
  /**
   * @fn readPH
   * @brief 通过温度补偿将电压转换为 PH值
   *
   * @param voltage     : 电压值
   * @param temperature : 环境温度值
   * @return PH值
   */
  float   readPH(float voltage, float temperature); 
  /**
   * @fn begin
   * @brief 初始化模拟 pH 传感器
   */
  void begin();
```

## 兼容性

MCU                | Work Well | Work Wrong | Untested  | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Arduino Uno  |      √       |             |            | 
Leonardo  |      √       |             |            | 
Meag2560 |      √       |             |            | 
esp32 series   |              |     x       |            |

## 历史

- 2018/11/06 - 1.0.0 版本

## 创作者

Written by Jiawei Zhang(jiawei.zhang@dfrobot.com), 2018. (Welcome to our [website](https://www.dfrobot.com/))



