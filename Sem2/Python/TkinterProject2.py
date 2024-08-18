from tkinter import *
import re

tk = Tk()
tk.title("Registration Window")
tk.geometry("1200x900+100+15")
tk.wm_iconbitmap("E:\Academics\College Academics\Codes\Sem2\Python\Images\download.ico")

def checkall():
    
    error_label1.config(text = "")
    error_label2.config(text = "")
    error_label3.config(text = "")
    error_label4.config(text = "")
    error_label5.config(text = "")
    error_label6.config(text = "")
    error_label7.config(text = "")

    if (len(name.get()) == 0):
        error_label1.config(text = "Error in field 1! Empty input not allowed")
    else:
        if (len(name.get()) > 50):
            error_label1.config(text = "Error in field 1! Maximum length of name is 50 characters")
        if (not(name.get().isalpha())):
            error_label1.config(text = "Error in field 1! Only alphabets are allowed in the name")
    
    if (len(email.get()) == 0):
        error_label2.config(text = "Error in field 2! Empty input not allowed")
    else:
        thestring = email.get()
        pattern1 = r"[A-z]@[A-z]+[.]+[A-z]"
        match = re.search(pattern1, thestring)
        if (not match):
            error_label2.config(text = "Error in field 2! Email Address should be valid")
    
    if (len(passwd.get()) == 0):
        error_label3.config(text = "Error in field 3! Empty input not allowed")
    if (len(mobile.get()) == 0):
        error_label4.config(text = "Error in field 4! Empty input not allowed")
    else:
        if (len(mobile.get()) != 10):
            error_label4.config(text = "Error in field 3! Mobile number must be valid (10 characters)")
    if (len(RollNo.get()) == 0):
        error_label5.config(text = "Error in field 5! Empty input not allowed")
    else:
         if (len(RollNo.get()) != 8):
            error_label5.config(text = "Error in field 4! Roll number must be valid (8 characters)")
    if (len(school.get()) == 0):
        error_label6.config(text = "Error in field 6! Empty input not allowed")
    if (len(college.get()) == 0):
        error_label7.config(text = "Error in field 7! Empty input not allowed")

title = Label(tk, text = "Student Registration Form", font = ("arial", 30, "bold"), fg = "black", bg = "gold", relief = RIDGE, bd = 10)
title.pack()

name_label = Label(tk, text = "Enter your name : ", font = ("Verdana", 20))
name_label.place(x = 0, y = 100)

name = StringVar()
name_entry = Entry(tk, font = ("Verdana", 20), textvariable = name, bd = 3, relief = RIDGE)
name_entry.place(x = 400, y = 100, relwidth = 0.6)

email_label = Label(tk, text = "Enter your email : ", font = ("Verdana", 20))
email_label.place(x = 0, y = 175)

email = StringVar()
email_entry = Entry(tk, font = ("Verdana", 20), textvariable = email, bd = 3, relief = RIDGE)
email_entry.place(x = 400, y = 175, relwidth = 0.6)

passwd_label = Label(tk, text = "Enter your password : ", font = ("Verdana", 20))
passwd_label.place(x = 0, y = 250)

passwd = StringVar()
passwd_entry = Entry(tk, font = ("Verdana", 20), textvariable = passwd, bd = 3, relief = RIDGE, show = "*")
passwd_entry.place(x = 400, y = 250, relwidth = 0.6)

mobile_label = Label(tk, text = "Enter your mobile number : ", font = ("Verdana", 20))
mobile_label.place(x = 0, y = 325)

mobile = StringVar()
mobile_entry = Entry(tk, font = ("Verdana", 20), textvariable = mobile, bd = 3, relief = RIDGE)
mobile_entry.place(x = 400, y = 325, relwidth = 0.6)

RollNo_label = Label(tk, text = "Enter your roll number : ", font = ("Verdana", 20))
RollNo_label.place(x = 0, y = 400)

RollNo = StringVar()
RollNo_entry = Entry(tk, font = ("Verdana", 20), textvariable = RollNo, bd = 3, relief = RIDGE)
RollNo_entry.place(x = 400, y = 400, relwidth = 0.6)

school_label = Label(tk, text = "Enter your school name : ", font = ("verdana", 20))
school_label.place(x = 0, y = 475)

school = StringVar()
school_entry = Entry(tk, font = ("times", 20), textvariable = school, bd = 3, relief = RIDGE)
school_entry.place(x = 400, y = 475, relwidth = 0.6)

college_label = Label(tk, text = "Enter your college name : ", font = ("verdana", 20))
college_label.place(x = 0, y = 550)

college = StringVar()
college_entry = Entry(tk, font = ("roman", 20), textvariable = college, bd = 3, relief = RIDGE)
college_entry.place(x = 400, y = 550, relwidth = 0.6)

submit = Button(tk, text = "Click here to submit", font = ("Verdana", 20), bg = "blue", fg = "white", bd = 5, relief = RIDGE, command = checkall)
submit.place(x = 600, y = 650)

error_label1 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label1.place(x = 10, y = 650)

error_label2 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label2.place(x = 10, y = 675)

error_label3 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label3.place(x = 10, y = 700)

error_label4 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label4.place(x = 10, y = 725)

error_label5 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label5.place(x = 10, y = 750)

error_label6 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label6.place(x = 10, y = 775)

error_label7 = Label(tk, text = "", font = ("verdana", 13), fg = "red")
error_label7.place(x = 10, y = 800)

tk.mainloop()