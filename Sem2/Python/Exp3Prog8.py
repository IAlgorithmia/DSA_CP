a, b, c = input("Enter the three sides of a triangle : ").split()
a = int(a)
b = int(b)
c = int(c)
if (a + b > c and a + c > b and b + c > a):
    print("The perimeter of the triangle is %d" % (a + b + c))
else:
    print("The entered values are invalid")
        
