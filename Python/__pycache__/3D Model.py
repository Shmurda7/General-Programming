import tkinter as tk
import serial.tools.list_ports
import serial
import time
import csv
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import sys 

data = pd.read_csv("data.csv")
print(data)

D = data.to_numpy()
t = D[:,0]
pan = D[:,1]
tilt = D[:,2]
r_us = D[:,3]+7
r_tof = D[:,4]+7

plt.plot(t,r_us)
plt.plot(t,r_tof)
plt.show()