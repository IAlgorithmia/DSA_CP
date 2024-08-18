import math
a, b, c = input("Enter the value of a, b and c : ").split()
a = int(a)
b = int(b)
c = int(c)
term = ((b**2) - 4*a*c)
if (term > 0):
    r1 = ((-b) + math.sqrt((b**2) - 4*a*c))/(2*a)
    r2 = ((-b) - math.sqrt((b**2) - 4*a*c))/(2*a)
    print("The two roots of the equation are : %.2f %.2f" % (r1, r2))
elif (term == 0):
    r = (-b)/(2*a)
    print("The repeating root of the equation is : %.2f" % (r))
else:
    print("The equation has no real roots!")
