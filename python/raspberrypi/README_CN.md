# DFRobot_PH

- [English Version](./README.md)

这是 Gravity 的示例代码：模拟 pH 传感器/仪表套件 V2，SKU：SEN0161-V2

![产品效果图](../../resources/images/SEN0161-V2.png)


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
1. 下载库至树莓派，要使用这个库，首先要将库下载到Raspberry Pi，命令下载方法如下:<br>
```python
sudo git clone https://github.com/DFRobot/DFRobot_PH
```
2. 打开并运行例程，要执行一个例程demo_x.py，请在命令行中输入python demo_x.py。例如，要执行 demo_PH_read.py例程，你需要输入:<br>

```python
python demo_PH_read.py 
或 
python2 demo_PH_read.py 
```

## 方法

```python
  '''!
    @brief   初始化模拟 pH 传感器.
  '''
  def begin(self):
		
  '''!
    @brief   通过温度补偿将电压转换为 PH值
    @param voltage       电压值
    @param temperature  环境温度值
    @return  PH值
  '''
  def read_PH(self,voltage,temperature):

  '''!
    @brief   使用校准参数校准PH计
    @param voltage       电压值
  '''
  def calibration(self,voltage):

  '''!
    @brief   将校准数据设置为默认值。
  '''	
  def reset(self):
```

## 兼容性

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

## 历史

- 2018/11/06 - 1.0.0 版本

## 创作者

Written by Jiawei Zhang(jiawei.zhang@dfrobot.com), 2018. (Welcome to our [website](https://www.dfrobot.com/))






