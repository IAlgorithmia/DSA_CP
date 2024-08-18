from tkinter import*

root = Tk()
root.title("My First GUI")
root.geometry("1000x500+200+50")
root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico") # Icon
# root.resizable(False, False)

i = 1
def onclick():
    global i
    label = Label(root, text = f"The Thing Is That You Rock! {entry.get()} {i}", font = ("Verdana", 15, "bold"))
    label.pack(side = TOP)
    i += 1
    
MyButton = Button(root, text = "Click me to see magic", font = ("Verdana", 15, "bold"), bg = "gold", fg = "black", command = onclick)
MyButton.pack(pady = 40)

entry = Entry(root, width = 30, font = ("Verdana", 20, "bold"), bg = "black", fg = "gold", bd = 5)
entry.pack(pady = 20)

root.mainloop()