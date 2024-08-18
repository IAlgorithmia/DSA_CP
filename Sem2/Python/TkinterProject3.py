from tkinter import *

tk = Tk()

tk.geometry("700x700+50+20")
tk.title("My GUI")
tk.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico")

frame1 = Frame(tk, bg = "green", bd = 5, relief = RIDGE)
frame1.place(x = 0, y = 0, height = 350, width = 350)

frame2 = Frame(tk, bg = "blue", bd = 5, relief = RIDGE)
frame2.place(x = 350, y = 0, height = 350, width = 350)

frame3 = Frame(tk, bg = "red", bd = 5, relief = RIDGE)
frame3.place(x = 0, y = 350, height = 350, width = 350)

frame4 = Frame(tk, bg = "yellow", bd = 5, relief = RIDGE)
frame4.place(x = 350, y = 350, height = 350, width = 350)

frame5 = Frame(tk, bg = "cyan", bd = 5, relief = RIDGE)
frame5.place(x = 175, y = 175, height = 175, width = 175)

frame6 = Frame(tk, bg = "orange", bd = 5, relief = RIDGE)
frame6.place(x = 350, y = 175, height = 175, width = 175)

frame7 = Frame(tk, bg = "pink", bd = 5, relief = RIDGE)
frame7.place(x = 175, y = 350, height = 175, width = 175)

frame8 = Frame(tk, bg = "purple", bd = 5, relief = RIDGE)
frame8.place(x = 350, y = 350, height = 175, width = 175)

tk.mainloop()