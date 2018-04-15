from Tkinter import *
import serial
class App :
    def __init__(self) :
        self.ser01=serial.Serial("/dev/rfcomm1", 9600)
        self.ser02=serial.Serial("/dev/rfcomm2", 9600)
        self.window=Tk()
        frame=Frame(self.window)
        self.label=Label(self.window, text="Bluethings Control System")
        self.label01=Label(self.window, text="콘센트 작동여부 : ")
        self.label02=Label(self.window, text="스위치 작동여부 : ")
        b1=Button(frame, text="콘센터 작동", command=self.turnOn1)
        b2=Button(frame, text="콘센터 끄기", command=self.turnOff1)
        b3=Button(frame, text="스위치 작동", command=self.turnOn2)
        b4=Button(frame, text="스위치 끄기", command=self.turnOff2)
        b5=Button(frame, text="종료", command=self.exitButton)
        b1.pack(side=LEFT)
        b2.pack(side=LEFT)
        b3.pack(side=LEFT)
        b4.pack(side=LEFT)
        b5.pack(side=LEFT)
        self.label.pack()
        self.label01.pack()
        self.label02.pack()
        frame.pack()
        self.window.mainloop()
    def turnOn1(self) :
        self.label['text']="콘센터가 작동됩니다."
        self.label01['text']="콘센트 작동여부 : ON"
        text="1\n"
        self.ser01.write(bytearray(text))
    def turnOff1(self) :
        self.label['text']="콘센터가 꺼집니다."
        self.label01['text']="콘센트 작동여부 : OFF"
        text="2\n"
        self.ser01.write(bytearray(text))
    def turnOn2(self) :
        self.label['text']="스위치가 작동됩니다."
        self.label02['text']="스위치 작동여부 : ON"
        text="1\n"
        self.ser02.write(bytearray(text))
    def turnOff2(self) :
        self.label['text']="스위치가 꺼집니다."
        self.label02['text']="스위치 작동여부 : OFF"
        text="2\n"
        self.ser02.write(bytearray(text))
    def exitButton(self) :
        self.ser01.close()
        self.ser02.close
        self.window.destroy()
        
App()
