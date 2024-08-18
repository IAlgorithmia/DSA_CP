class Finance:
    def __init__(self):
        self.__revenue = 200000
        self.number_of_sales = 114
    def display(self):
        print(f"The revenue is {self.__revenue} and the number of sales is {self.number_of_sales}")
f1 = Finance()
print(f"{f1.number_of_sales}")   
print(f"{f1.__revenue}")   
#Here we can say that encapsulation has been applied on revenue but not on number_of_sales, since revenue ko na to access na to change kar sakte outside the class without using inclass emthods. It is tied up with the methods, unlike number_of_sales
print(f1.__dict__)
class HR:
    def __init__(self):
        self.number_of_employee = 30
        f1.revenue = 2 #this will throw an error
h1 = HR()
print(f1.__dict__)
#Encapsulation means wrapping up (data) and (methods working on data) together in a single class. It is achieved by declaring data and methods of a class as private.