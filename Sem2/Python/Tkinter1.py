from tkinter import* # One of the way to use tkinter module

# import tkinter as tk is also valid #2

root = Tk() # Creates a window 
root.title("My First GUI") # Title
root.geometry("1000x500+200+50") # Dimensions
root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico") # Icon
root.resizable(False, False) # Resizability

# root = Tk() is in accordance with #2

root.mainloop() # Window doesn't close as soon as it opens

'''Below is the standard code : 
from tkinter import*

root = Tk()
root.title("My First GUI")
root.geometry("1000x500+200+50")
root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\download.ico") # Icon
root.resizable(False, False)

root.mainloop()
'''