class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
    def show(self):
        print(f"The name is {self.name} and the salary is {self.salary}")
    @classmethod
    def fromstr(cls, string):
        return cls(string.split("-")[0], int(string.split("-")[1])) #Is instance ka ek modified form return kardo
e1 = Employee("Jacob", 12000)
e1.show()
thestring = "Jason-50000"
e2 = Employee.fromstr(thestring) #Equivalent to Employee("Jason", 50000)
e2.show()