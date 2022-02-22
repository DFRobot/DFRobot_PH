
'''!
  @file demo_EC_reset.py
  @brief This example ues to reset ecdata.txt to default value
  @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
  @license     The MIT License (MIT)
  @author [Jiawei Zhang](jiawei.zhang@dfrobot.com)
  @version  V1.0
  @date  2018-11-06
  @url https://github.com/DFRobot/DFRobot_PH
'''
import sys
sys.path.append('../')
import time

from DFRobot_EC import DFRobot_EC
ec = DFRobot_EC()

ec.reset()
time.sleep(0.5)
sys.exit(1)