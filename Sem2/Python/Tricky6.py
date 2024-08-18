class Employee:
    name = "John"
    def __len__(self):
        i = 0
        for c in self.name:
            i += 1
        return i
e = Employee()
print(e.__len__())
print(len(e)) #In this way, dunder moethd can be called in two ways, also, these methods are automatically envoked and called when a class object is created
print(e.name)