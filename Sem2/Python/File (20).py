class Employee:
    company_name = "Apple"
    employee_num = 0
    def __init__(self, name):
        self.name = name
        self.raise_amount = 25000
        Employee.employee_num += 1 #This is a class variable
    def showdetails(self):
        print(f"The name is {self.name} and his raise amount is {self.raise_amount} and the company name is {self.company_name} of size {self.employee_num} employees")
emp1 = Employee("Harry")
emp1.raise_amount = 30000
emp1.company_name = "Google"
emp1.showdetails()
Employee.company_name = "Microsoft"
emp2 = Employee("Jasoooos")
emp2.company_name = "ITC"
emp2.showdetails()
# Employee.showdetails(emp1) this is the same as above