from tkinter import *
from PIL import Image, ImageTk
from tkinter import ttk

tk = Tk()

tk.title("New Message")
tk.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\mail.ico")
tk.geometry("700x800+50+50")

label2 = Label(tk, text = "To : ", font = ("Verdana", 15))
label2.place(x = 0, y = 50)

entry2 = Entry(tk, font = ("verdana", 15))
entry2.place(x = 150, y = 50, relwidth = 0.75)

label3 = Label(tk, text = "From : ", font = ("Verdana", 15))
label3.place(x = 0, y = 100)

entry3 = Entry(tk, font = ("verdana", 15))
entry3.place(x = 150, y = 100, relwidth = 0.75)

label4 = Label(tk, text = "CC : ", font = ("Verdana", 15))
label4.place(x = 0, y = 150)

entry4 = Entry(tk, font = ("verdana", 15))
entry4.place(x = 150, y = 150, relwidth = 0.75)

label5 = Label(tk, text = "BCC : ", font = ("Verdana", 15))
label5.place(x = 0, y = 200)

entry5 = Entry(tk, font = ("verdana", 15))
entry5.place(x = 150, y = 200, relwidth = 0.75)

label6 = Label(tk, text = "Subject : ", font = ("Verdana", 15))
label6.place(x = 0, y = 250)

entry6 = Entry(tk, font = ("verdana", 15))
entry6.place(x = 150, y = 250, relwidth = 0.75)

label7 = Label(tk, text = "Message : ", font = ("Verdana", 15))
label7.place(x = 0, y = 300)

textbox1 = Text(tk, font = ("Verdana", 15))
textbox1.place(x=  150, y = 300, relwidth = 0.75, relheight = 0.25)

mybutton4 = Button(tk, text = "Send", fg = "white", bg = "blue", font = ("Verdana", 15, "bold"), cursor = "hand2", activeforeground = "blue", activebackground = "white")
mybutton4.place(x = 10, y = 550)

myimage5 = ImageTk.PhotoImage(Image.open(r"E:\Academics\College Academics\Codes\Sem2\Python\Images\file.png"))
mybutton5 = Button(tk, image = myimage5)
mybutton5.place(x = 100, y = 552, width = 40, height = 40)

myimage6 = ImageTk.PhotoImage(Image.open(r"E:\Academics\College Academics\Codes\Sem2\Python\Images\image.png"))
mybutton6 = Button(tk, image = myimage6)
mybutton6.place(x = 150, y = 552, width = 40, height = 40)

myimage7 = ImageTk.PhotoImage(Image.open(r"E:\Academics\College Academics\Codes\Sem2\Python\Images\dustbin.png"))
mybutton7 = Button(tk, image = myimage7)
mybutton7.place(x = 650, y = 545, width = 40, height = 40)

myimage8 = ImageTk.PhotoImage(Image.open(r"E:\Academics\College Academics\Codes\Sem2\Python\Images\emoji.png"))
mybutton8 = Button(tk, image = myimage8)
mybutton8.place(x = 200, y = 552, width = 40, height = 40)

mydropdown = ttk.Combobox(tk, value = ("Select Option", "Default to full screen", "Label", "Plain Text Mode", "Print", "Check Spelling", "Smart Compose Feedback", "Schedule Send"), width = 12, state = "readonly", font = ("Verdana", 10))
mydropdown.set("Select Option")
mydropdown.place(x = 255, y = 560)

tk.mainloop()