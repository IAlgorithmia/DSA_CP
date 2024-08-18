class string:
    def __init__(self):
        pass
    def get_string(self):
        self.mystring = input("Enter the string : ")
        #Any variables that we create have to be initialized as instance variables so that they can be used throughout the class
    def print_string(self):
        print(self.mystring)
object = string()
object.get_string()
object.print_string()  