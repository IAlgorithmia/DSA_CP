class Person:
    name = "Vaibhav"
    occupation = "Undergrad"
    networth = "5000000 sandwiches"
    def info(self):
        print(f"{self.name} is a/an {self.occupation}")
a = Person()
b = Person()
c = Person()
a.name = "Jason"
b.name = "Harry"
a.occupation = "Driver"
b.occupation = "Teacher"
a.info()
b.info()
c.info()