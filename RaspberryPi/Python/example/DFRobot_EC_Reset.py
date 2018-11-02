#This example ues to reset ecdata.txt to default value
import sys
sys.path.append('../')
import time

from DFRobot_EC import DFRobot_EC
ec = DFRobot_EC()

ec.reset()
time.sleep(0.5)
sys.exit(1)