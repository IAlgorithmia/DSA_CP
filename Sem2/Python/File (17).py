class Employee:
    def __init__(self, name, ID):
        self.name = name
        self.id = ID
    #dekho, id, name vagerah to vaise hi properties hain, @property use karke hum funcions ko bhi property bana sakte hain
    def showdetails(self):
        print(f"The employee {self.name} has the ID {self.id}")
class Pogrammer(Employee): #this class just becomes an extention of class employee
    @property
    def showlanguage(self):
        print(f"The default language is python!")
e = Employee("Rohan", 460)
e.showdetails()
p = Pogrammer("Jason", "89")
p.showdetails()
p.showlanguage