class Circle:
    def __init__(self, radius):
        self.radius = radius
    def area(self):
        print("The area of the circle is : ", (3.14 * ((self.radius)**2)), " unit squared")
    def perimeter(self):
        print("The perimeter of the circle is : ", (2 * 3.14 * self.radius), " units")
object = Circle(15)
object.area()
object.perimeter()