'''
@author: zhonghuiping
'''
from tkinter import *
import time

class Application(Frame):
    """Jungle Timers"""

    def __init__(self, master):
        """Initialize the Frame."""
        Frame.__init__(self, master)
        self.bx=0
        self.rx=0
        self.b2x=0
        self.r2x=0
        self.dx=0
        self.baron=0
        self.grid()
        self.create_widgets()


    def create_widgets(self):
        """Buttons for timer."""
        #create buttons
        self.b1 = Button(self, text = "Own Blue Up In: 0", command = self.b1)
        self.b1.grid()

        self.r1 = Button(self, text = "Own Red Up In: 0", command = self.r1)
        self.r1.grid()

        self.b2 = Button(self, text = "Their Blue Up In: 0", command = self.b2)
        self.b2.grid()

        self.r2 = Button(self, text = "Their Red Up In: 0", command = self.r2)
        self.r2.grid()

        self.d = Button(self, text = "Dragon Up In: 0", command = self.d)
        self.d.grid()

        self.baron = Button(self, text = "Baron Up In: 0", command = self.baron)
        self.baron.grid()

    def b1(self):
        self.bx +=1
        self.b1.config(text = "Own Blue Up In: %d" % self.bx)


    def r1(self):
        self.rx +=1
        self.r1.config(text = "Own Blue Up In: %d" % self.rx)
    

    def b2(self):
        self.b2x +=1
        self.b2.config(text = "Own Blue Up In: %d" % self.b2x)

    def r2(self):
        self.r2x +=1
        self.r2.config(text = "Own Blue Up In: %d" % self.r2x)

    def d(self):
        self.dx +=1
        self.d.config(text = "Own Blue Up In: %d" % self.dx)

    def baron(self):
        self.baronx +=1
        self.baron.config(text = "Own Blue Up In: %d" % self.baronx)  

root = Tk()
root.title("Jungle Timers")
root.geometry("200x210")

app = Application(root)

root.mainloop()