#works on class variables
class employee:
    company_name="infosys"
    def __init__(self,nm,sal):
        self.name=nm
        self.salary=sal
    @classmethod
    def get_company_name(cls):
        print(cls.company_name)
        cls.company_name="tcs"
        print(cls.company_name)
        pass
e1=employee("abc",45) 
e2=employee("xyz",67)
employee.get_company_name()
e1.get_company_name()