import math
x = int(input("Enter the length from the center of pentagon to a vertex in meters : "))
s = 2 * x * (math.sin(3.14/5))
area = (3 * (math.sqrt(3)) * (s**2))/2
print("The area of the pentagon is %.2f meters squared" % (area))
