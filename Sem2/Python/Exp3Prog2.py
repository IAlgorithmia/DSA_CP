a, b, c, d, e, f = input("Enter a, b, c, d, e and f : ").split()
a = int(a)
b = int(b)
c = int(c)
d = int(d)
e = int(e)
f = int(f)
if ((a*d) - (b*c) == 0):
    print("The equations have no solution!")
else:
    x = ((e*d) - (b*f))/((a*b) - (b*c))
    y = ((a*f) - (e*c))/((a*b) - (b*c))
    print("The two roots of the equation are : %.2f and %.2f" % (x, y))
