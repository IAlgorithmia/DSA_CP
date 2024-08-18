from tkinter import*

root = Tk()

root.title("My First GUI")

root.geometry("1200x800+50+10")

root.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico")

root.resizable(False, False) #`This would've disabled the resize option in the window

# thetext = "I'm Vaibhav, nice to meet you!\nHow are you?"
# label = Label(root, text = thetext, font = ("Verdana", 20, "bold")) 
#The above lines also work

# label = Label(root, text = "I'm Vaibhav, nice to meet you!\nHow are you?", font = ("Verdana", 20, "bold"))
# label.pack(side = RIGHT)
# label = Label(root, text = "I'm Vaibhav, nice to meet you!\nHow are you?", font = ("Verdana", 20, "bold"))
# label.pack(side = LEFT)
# label = Label(root, text = "I'm Vaibhav, nice to meet you!\nHow are you?", font = ("Verdana", 20, "bold"))
# label.pack(side = TOP)
# label = Label(root, text = "I'm Vaibhav, nice to meet you!\nHow are you?", font = ("Verdana", 20, "bold"))
# label.pack(side = BOTTOM)

# label = Label(root, text = "I'm Falling so... 1", font = ("Verdana", 15, "bold"))
# label.grid(row = 0, column = 0)
# label = Label(root, text = "I'm Falling so... 2", font = ("Verdana", 15, "bold"))
# label.grid(row = 0, column = 1)
# label = Label(root, text = "I'm Falling so... 3", font = ("Verdana", 15, "bold"))
# label.grid(row = 2, column = 0)

# label = Label(root, text = "I'm outta payphone!", font = ("Verdana", 20, "bold"))
# label.place(x = 100, y = 100)
# label = Label(root, text = "I'm outta payphone! Again", font = ("Verdana", 20, "bold"))
# label.place(x = 500, y = 500)

root.mainloop()