from tkinter import*

root = Tk()
root.title("My First GUI")
root.geometry("1000x500+200+50")
root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico") # Icon
# root.resizable(False, False)

def onclick():
    mytext = "Hello " + entry.get()
    label.config(text = mytext)
    
entry = Entry(root, width = 30, font = ("Verdana", 20, "bold"), bg = "black", fg = "gold", bd = 5)
entry.place(x = 0, y = 50, relwidth = 1) #Relation width - given in float parent ke relation mein iski width kitni hogi, this overrides the width specification in the abovev line of code
    
MyButton = Button(root, text = "Click me to see magic", font = ("Verdana", 15, "bold"), bg = "gold", fg = "black", command = onclick)
MyButton.place(x = 0, y = 200, relwidth = 1)

textbox = Text(root, font = ("Verdana", 20, "bold") )
textbox.place(x = 0, y = 300, relwidth = 1, relheight = 0.2)

label = Label(root, text = f"The Thing Is That You Rock!", font = ("Verdana", 15, "bold"))
label.place(x = 0, y = 450, relwidth = 1)

root.mainloop()