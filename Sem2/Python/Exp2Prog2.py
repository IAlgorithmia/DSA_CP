import math
l = int(input("Enter the length of the side of pentagon in meters : "))
area = (5*(l**2))/(4*(math.tan(3.14/5)))
print("The area of the pentagon is %.2f meters squared" % (area))
