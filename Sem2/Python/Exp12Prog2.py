from tkinter import *

tk = Tk()

tk.title("My first GUI")
text = "Vaibhav is a good man, not a nice guy"
label = Label(tk, text = text)
label.place(x = 50, y = 50)

tk.mainloop()