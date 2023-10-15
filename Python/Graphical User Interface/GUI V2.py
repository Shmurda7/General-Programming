import sys
from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtWidgets import QApplication, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QTextEdit, QPushButton
from PyQt5.QtCore import QTimer, Qt
import pyqtgraph as pg
import serial

class MainWindow(QWidget):
    def __init__(self):
        super().__init__()

        # Create a timer object and set its timeout signal to call the update() method
        self.timer = QTimer()
        self.timer.timeout.connect(self.update)

        # Create a serial connection to the Arduino
        self.ser = serial.Serial('COM4', 115200)

        # Create widgets for the GUI
        self.textbox = QTextEdit()
        self.textbox.setReadOnly(True)
        self.plot = pg.PlotWidget()

        self.start_button = QPushButton('Start')
        self.start_button.setCheckable(True)
        self.start_button.setChecked(False)
        self.start_button.clicked.connect(self.start_stop_data)

        # Create layouts for the GUI
        vbox_left = QVBoxLayout()
        vbox_left.addWidget(self.textbox)
        vbox_left.addWidget(self.start_button)

        hbox = QHBoxLayout()
        hbox.addLayout(vbox_left)
        hbox.addWidget(self.plot)

        self.setLayout(hbox)

        # Initialize variables for the data
        self.x = []
        self.y = []

        # Set up the plot
        self.plot.setLabel('left', 'Accelerometer Reading')
        self.plot.setLabel('bottom', 'Time')
        self.plot.setXRange(0, 10)
        self.plot.setYRange(-10, 10)

        self.curve = self.plot.plot(pen='y')

    def start_stop_data(self):
        if self.start_button.isChecked():
            self.timer.start(10)
            self.ser.write(b'start')
        else:
            self.timer.stop()
            self.ser.write(b'stop')

    def update(self):
        # Read data from the serial connection
        data = self.ser.readline().decode().strip()
        if data.startswith('Time'):
            return
        # Split the data into its components
        values = data.split('\t')
        xaccel = float(values[0])
        yaccel = float(values[1])
        zaccel = float(values[2])

        # Update the plot
        self.x.append(self.x[-1] + 0.01 if self.x else 0)
        self.y.append(xaccel)
        self.curve.setData(self.x, self.y)

        # Update the textbox
        self.textbox.moveCursor(QtGui.QTextCursor.End)
        self.textbox.insertPlainText(data + '\n')

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
