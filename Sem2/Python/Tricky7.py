class Employee:
    name = "Vaibhav" 
    def __init__(self, name):
        self.name = name
        print("Bachna hai haseeno")
e = Employee("JesusFrickinChrist")
print(e.name)
print(Employee.name)