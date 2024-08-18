class Employee:
    name = "John"
    def __len__(self):
        i = 0
        for c in self.name:
            i += 1
        return i
    def __str__(self):
        return f"This class is of Employee {self.name} str"
    def __repr__(self):
        return f"Employee ('{self.name}')"
    #Str method is called automatically when e is called
    # repr method is called either when called specially or when stris not available
    def __call__(self):
        print("Hey I'm good")
    #This method is called when the object is called as a function liek object()
e = Employee()
print(e.__len__())
print(len(e)) #In this way, dunder moethd can be called in two ways, also, these methods are automatically envoked and called when a class object is created
print(e.name)