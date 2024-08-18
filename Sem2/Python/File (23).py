class vehicle:
    def __init__(self, type, color, price):
        self.color = color
        self.type = type
        self.color = color
        self.price = price
    def max_speed(self):
        print(f"The max speed of {self.type} is 100")
class moreover(vehicle):
    def about(self):
        print("This is just an unnecessary extention of the class vehicle")
    def max_speed(self):
        print(f"The max speed of {self.type} is 150")
v = vehicle("SUV","Black", "25L")
c = moreover("Sedan", "Blue", "20L")
c.about()
v.max_speed()
c.max_speed()
#According to the situation and the object type, the behaviour of the function max_sped changes, this is termed as polymorphism. One function is behaving in more than 1 way!