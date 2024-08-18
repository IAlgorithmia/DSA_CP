class Employee:
    def __init__(self):
        self.__name = "Harry"
class Student:
    def __init__(self):
        self._name = "Harry"
    def _funname(self):
        return "Code with harry"
class Subject(Student):
    pass
a = Employee()
print(a._Employee__name)
print(a.__dir__())
obj1 = Subject()
obj2 = Student()
print(obj1._name)
print(obj1._funname())
print(obj2._name)
print(obj2._funname())