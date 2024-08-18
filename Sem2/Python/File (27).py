class Employee:
    company_name = "Infosys"
    def __init__(self, sal, ag):
        self.salary = sal
        self.age = ag
    @classmethod
    def get_company_name(cls):
        print(f"The company name is {cls.company_name}")
        cls.company_name = "Microsoft"
        print(f"The company name is {cls.company_name}")
e = Employee(25000, 15)
print(e.company_name)
print(Employee.company_name)
Employee.get_company_name()
print(Employee.company_name)