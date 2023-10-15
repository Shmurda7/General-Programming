from PyQt5 import QtCore, QtGui, QtWidgets
from PyQt5.QtGui import QFont
from PyQt5.QtWidgets import QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout, QLabel, QPushButton, QTableWidget, QTableWidgetItem
from PyQt5.QtCore import Qt, QTimer
import serial


#### note to self open with designer in the terminal######

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()
        # Set window properties
        self.setWindowTitle("GUI V1")
        self.setGeometry(100, 100, 1280, 1000)

        # Set up main widget
        self.centralWidget = QWidget()
        self.setCentralWidget(self.centralWidget)

        # Set up layout
        self.layout = QHBoxLayout(self.centralWidget)

        # Set up data table widget
        self.dataTable = QTableWidget()
        self.dataTable.setFont(QtGui.QFont("Arial", 10, QtGui.QFont.Bold))
        self.dataTable.setColumnCount(13)
        self.dataTable.setHorizontalHeaderLabels(['Time', 'AX', 'AY', 'AZ', 'GX', 'GY', 'GZ', 'MX', 'MY', 'MZ', 'Roll', 'Pitch', 'Yaw'])
        self.layout.addWidget(self.dataTable)

        # Set up control widget
        self.controlWidget = QWidget()
        self.controlLayout = QVBoxLayout(self.controlWidget)
        self.layout.addWidget(self.controlWidget)

        # Set up control button
        self.controlButton = QPushButton("Start")
        self.controlButton.setFont(QtGui.QFont("Arial", 10, QtGui.QFont.Bold))
        self.controlLayout.addWidget(self.controlButton)

        # Set up serial connection
        self.serial = serial.Serial('COM4', 115200)

        # Set up timer to update data
        self.timer = QTimer()
        self.timer.timeout.connect(self.updateData)

        # Connect button to start/stop timer
        self.controlButton.clicked.connect(self.toggleTimer)

        # Set up style sheet for light/dark mode
        self.lightStyleSheet = "background-color: #F0F0F0;"
        self.darkStyleSheet = "background-color: #222222; color: #FFFFFF;"
        self.setStyleSheet(self.lightStyleSheet) # set default style sheet to light mode


    def toggleTimer(self):
        if not self.timer.isActive():
            self.timer.start()
            self.controlButton.setText("Stop")
        else:
            self.timer.stop()
            self.controlButton.setText("Start")

        # Set up deque to store 'AX' values and corresponding timestamps
    def updateData(self):
        # Read data from serial
        data = self.serial.readline().decode().strip().split('\t')

        # Ensure data has expected number of columns
        if len(data) != 13:
            return

        # Insert new row at the beginning of the table
        self.dataTable.insertRow(0)
        for columnPosition, value in enumerate(data):
            item = QTableWidgetItem(value)
            item.setTextAlignment(Qt.AlignCenter)
            font = QFont()
            font.setBold(False)
            item.setFont(font)
            self.dataTable.setItem(0, columnPosition, item)

        # Remove the last row if there are too many rows
        if self.dataTable.rowCount() > 1000:
            self.dataTable.removeRow(self.dataTable.rowCount() - 1)


if __name__ == '__main__':
    app = QApplication([])
    window = MainWindow()
    window.show()
    app.exec_()

