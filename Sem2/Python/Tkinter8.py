from tkinter import*

root = Tk()
root.title("My First GUI")
root.geometry("1000x500+200+50")
root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico") # Icon
root.resizable(False, False)

def onclick():
    if (whether.get() == 0):
        mylabel.config(text = "The user has agreed to all the requirements!")
    else:
        mylabel.config(text = "The user has not agreed to all the requirements!")

whether = IntVar()
mychecker = Checkbutton(root, variable = whether, offvalue = 0, onvalue = 1, text = "Agree to our terms and conditions? ", font = ("Verdana", 20, "bold"))
mychecker.place(x = 100, y = 100)

mybutton = Button(root, text = "Click me for magic", font = ("Verdana", 20, "bold"), command = onclick)
mybutton.place(x = 200, y = 300)

mylabel = Label(root, text = 'Area reserved for text', font = ("Verdana", 20, "bold"), bg = "gold", fg = "black")
mylabel.place(x = 100, y = 200)

root.mainloop()