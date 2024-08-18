from tkinter import*

root = Tk()
root.title("My First GUI")
root.geometry("1000x500+200+50")
root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico") # Icon
# root.resizable(False, False)

mylabel = Label(root, text = "Course Details", font = ("verdana", 20, "bold"), bg = "gold", fg = "black", bd = 10, relief = RIDGE)
mylabel.place(x = 375, y = 0)

entry = Entry(root, font = ("verdana", 20, "bold"), highlightthickness = 2, borderwidth = 2, relief = RIDGE, fg = "cyan", bg = "green", show = "*")
entry.place(x = 0, y = 100, relwidth = 1)

but = Button(root, text = "Course Details", font = ("verdana", 40, "bold"), activebackground = "yellow", activeforeground = "blue", bg = "blue", fg = "yellow", borderwidth = 10, relief = RIDGE, cursor = "hand2")
but.place(x = 235, y = 200)

root.mainloop()