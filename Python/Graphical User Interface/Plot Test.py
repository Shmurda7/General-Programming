import serial
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
import numpy as np
import re

# open serial port
ser = serial.Serial('COM4', 115200)

# create figure and axes for plotting
fig, (ax1, ax2, ax3) = plt.subplots(3, 1)
fig.suptitle('IMU Data')

# set plot properties
x_len = 200  # number of points to display
y_range = [-180, 180]  # range of y-axis
x = list(range(0, x_len))
y1 = [0] * x_len
y2 = [0] * x_len
y3 = [0] * x_len

# create line objects for each plot
line1, = ax1.plot(x, y1)
line2, = ax2.plot(x, y2)
line3, = ax3.plot(x, y3)

# set plot labels
ax1.set_ylabel('Roll (degrees)')
ax2.set_ylabel('Pitch (degrees)')
ax3.set_ylabel('Yaw (degrees)')
ax3.set_xlabel('Time')

# function to read data from serial port
def get_data():
    # read data from file
    with open("data.txt", "r") as f:
        data = f.readlines()

    # extract roll, pitch, and yaw from data
    roll = float(re.sub("[^0-9.-]", "", data[7]))
    pitch = float(re.sub("[^0-9.-]", "", data[8]))
    yaw = float(re.sub("[^0-9.-]", "", data[9]))

    return roll, pitch, yaw


# function to update plot data
def update_plot(i):
    roll, pitch, yaw = get_data()
    y1.append(roll)
    y2.append(pitch)
    y3.append(yaw)
    y1.pop(0)
    y2.pop(0)
    y3.pop(0)
    line1.set_ydata(y1)
    line2.set_ydata(y2)
    line3.set_ydata(y3)
    return line1, line2, line3,

# create animation object
ani = FuncAnimation(fig, update_plot, interval=50, blit=True)

# show plot
plt.show()

# close serial port
ser.close()
