class Person():
    def __init__(self, n, o):
        self.name = n
        self.occ = o
        print("Hey, this function is being called!")
    def info(self):
        print(f"{self.name} is a/an {self.occ}")
a = Person("Vaibhav", "Inventor")
a.info()
b = Person("Mark", "Motivator")
b.info()