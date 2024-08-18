from tkinter import *

tk = Tk()

tk.geometry("1000x700+50+20")
tk.title("My GUI")
tk.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico")

frame1 = Frame(tk, bg = "green", bd = 5, relief = RIDGE)
frame1.place(x = 100, y = 100, height = 200, width = 300)#It's necessary to input the height and width when making a frame

label_frame1 = LabelFrame(tk, text = "This is a lebelled frame", font = ("Verdane", 10), bg = "cyan", bd = 29, relief = RIDGE)
label_frame1.place(x = 400, y = 400, height = 200, width = 300)

tk.mainloop()