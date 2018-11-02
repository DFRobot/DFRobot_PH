#This example ues to reset phdata.txt to default value
import sys
sys.path.append('../')
import time

from DFRobot_PH import DFRobot_PH
ph = DFRobot_PH()

ph.reset()
time.sleep(0.5)
sys.exit(1)