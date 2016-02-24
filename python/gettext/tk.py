#!/usr/bin/env pythonimport locale
import Tkinter
import locale
import gettext  
import tkMessageBox

gettext.find("tk", localedir="locale", all=True)  
t = gettext.translation('tk', "locale", languages=[locale.getdefaultlocale()[0]], fallback=True)  
_=t.ugettext
top = Tkinter.Tk()
class MyGUI:
    def __init__(self):
        self.main_window = top
        #Lable
        Tkinter.Label(self.main_window,text=_('Hello World!')).pack()
        Tkinter.Label(self.main_window,text=_('This is my GUI program.')).pack()
        #Button
        Tkinter.Button(self.main_window, text =_('Hello'), command = self.helloCallBack).pack()
        #Canvas
        self.canvas = Tkinter.Canvas(self.main_window, bg="blue", height=200, width=300)
        self.coord = 10, 50, 240, 210
        arc = self.canvas.create_arc(self.coord, start=0, extent=90, fill="red")
        self.canvas.pack()
        #Checkbutton
        Tkinter.Checkbutton(self.main_window, text = _("Music"), onvalue = 1, offvalue = 0, height=2, width = 10).pack()
        Tkinter.Checkbutton(self.main_window, text = _("Video"), onvalue = 1, offvalue = 0, height=2, width = 10).pack()
        #Scale
        self.var = Tkinter.DoubleVar()
        Tkinter.Scale(self.main_window, resolution = 0.0001, variable = self.var ,orient = Tkinter.HORIZONTAL).pack(anchor=Tkinter.CENTER)
        Tkinter.Button(self.main_window, text="Get Scale Value", command=self.sel).pack(anchor=Tkinter.CENTER)
        self.label = Tkinter.Label(self.main_window)
        self.label.pack()
        #Quit
        Tkinter.Button(self.main_window, text=_('Quit'), command=self.main_window.quit).pack(anchor=Tkinter.CENTER)
    def helloCallBack(self):
        tkMessageBox.showinfo(_('Hello Python'), _('Hello World!'))

    def sel(self):
        self.selection = "Value = " + str(self.var.get())
        self.label.config(text = self.selection)

mygui = MyGUI()
top.mainloop()
