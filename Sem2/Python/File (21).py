class Employee:
    company = "Apple"
    def show(anything): #Jaroori nahi hain har jagah self hi ho humara variable
        print(f"The name is {anything.name} and company is {anything.company}") #Yahan Employee.company bhi chalta hai
    @classmethod #Using this we can change the class varialbe
    def changecompany(cls, newcompany): #Jaroori nahi hain har jagah self hi ho humara variable
        cls.company = newcompany #isne sirf cls instance ke detail change kari hai, class variable ki nahi
e = Employee()
e.name = "Jason R" #hume banana pada since class mein nahi hai
e.show()
e.changecompany("Tesla")
e.show()
print(Employee.company)