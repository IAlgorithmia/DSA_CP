class GeometricObject:
    pass
class triangle(GeometricObject):
    def __init__(self, side1 = 1.0, side2 = 1.0, side3 = 1.0):
        self.side1 = side1
        self.side2 = side2
        self.side3 = side3
    def knowsides(self):
        return self.side1, self.side2, self.side3
    def getArea(self):
        self.perimeter = self.side1 + self.side2 + self.side3 
        return self.perimeter
    def __str__(self):
        string = f'This the triangle that has been created has the sides {self.side1}, {self.side2}, {self.side3} and the perimeter {self.perimeter}'
        return string
object = triangle(5.0, 5.0)
s1, s2, s3 = object.knowsides()
print(f"The sides are {s1}, {s2} and {s3}")
peri = object.getArea()
# We can also write peri = object.perimeter, but only after calling the class getArea
print(f"The perimeter of the triangle is {peri}")
info = object.__str__()
#Since we have used Magic/Dunder method, we can also write info = str(object)
print(info)