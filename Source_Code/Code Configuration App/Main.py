import sys
import serial
import time
from PyQt5.QtWidgets import QApplication, QMainWindow
from PyQt5.uic import loadUi

# Khởi tạo kết nối với Arduino thông qua cổng COM3 và baudrate 115200
ser = serial.Serial('COM11', 115200)

class MainWindow(QMainWindow):
    def __init__(self):
        super(MainWindow, self).__init__()
        loadUi('GUI.ui', self) # Load file UI được thiết kế bằng Qt Designer
        self.btnUP.clicked.connect(self.changeUP) 
        self.btnDOWN.clicked.connect(self.changeDOWN)
        self.btnRIGHT.clicked.connect(self.changeRIGHT)
        self.btnLEFT.clicked.connect(self.changeLEFT)
        self.btnSK1.clicked.connect(self.changeSK1) 
        self.btnSK2.clicked.connect(self.changeSK2)
        self.btnSK3.clicked.connect(self.changeSK3)
        self.btnSK4.clicked.connect(self.changeSK4)
    
    # Hàm xử lý sự kiện khi người dùng nhấn nút "Update"

    def changeUP(self):
        # Lấy kí tự mới từ textbox   
        text0 = self.tbUP.text()
        data0 = "0" + text0
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data0.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbUP.setText("UP: " + text0)


    def changeDOWN(self):
        # Lấy kí tự mới từ textbox   
        text1 = self.tbDOWN.text()
        data1 = "1" + text1
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data1.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbDOWN.setText("DOWN: " + text1)


    def changeRIGHT(self):
        # Lấy kí tự mới từ textbox   
        text2 = self.tbRIGHT.text()
        data2 = "2" + text2
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data2.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbRIGHT.setText("RIGHT: " + text2) 



    def changeLEFT(self):
        # Lấy kí tự mới từ textbox   
        text3 = self.tbLEFT.text()
        data3 = "3" + text3
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data3.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbLEFT.setText("LEFT: " + text3)



    def changeSK1(self):
        # Lấy kí tự mới từ textbox   
        text4 = self.tbSK1.text()
        data4 = "4" + text4
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data4.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbSK1.setText("SKILL1: " + text4)


    def changeSK2(self):
        # Lấy kí tự mới từ textbox   
        text5 = self.tbSK2.text()
        data5 = "5" + text5
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data5.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbSK2.setText("SKILL2: " + text5)


    def changeSK3(self):
        # Lấy kí tự mới từ textbox   
        text6 = self.tbSK3.text()
        data6 = "6" + text6
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data6.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbSK3.setText("SKILL3: " + text6) 



    def changeSK4(self):
        # Lấy kí tự mới từ textbox   
        text7 = self.tbSK4.text()
        data7 = "7" + text7
        # Gửi kí tự mới vào địa chỉ 0 của EEPROM
        ser.write(data7.encode())
        # Đợi 1 giây để Arduino xử lý
        time.sleep(1)
        # Đọc lại kí tự đã được ghi vào EEPROM và hiển thị lên label
        self.lbSK4.setText("SKILL4: " + text7)       

if __name__ == '__main__':
    app = QApplication(sys.argv)
    window = MainWindow()
    window.show()
    sys.exit(app.exec_())
