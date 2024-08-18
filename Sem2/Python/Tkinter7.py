from tkinter import *

tk = Tk()

tk.title("My GUI")
tk.wm_iconbitmap(r"E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico")
# tk.resizable(False, False)
tk.geometry("1200x700+200+50")

def worker():
    mytext = name.get() + " is a " + gender.get()
    label.config(text = mytext)

gender = StringVar()
radio1 = Radiobutton(tk, variable = gender, value = "Male", text = "Male", font = ("Verdana", 20, "bold"))
radio1.place(x = 100, y = 100)
gender.set("empty")

radio2 = Radiobutton(tk, variable = gender, value = "Female", text = "Female", font = ("Verdana", 20, "bold"))
radio2.place(x = 300, y = 100)

mybutton = Button(tk, text = "Click to see magic", font = ("Verdana", 20, "bold"), command = worker)
mybutton.place(x = 125, y = 200)

name = StringVar()
entry = Entry(tk, textvariable = name, font = ("Verdana", 20, "bold"))
entry.place(x = 100, y = 300, relwidth = 0.5)

label = Label(tk, text = "", font = ("Verdana", 20, "bold"))
label.place(x = 100, y = 400)

tk.mainloop()