r, l = int(input("Enter the radius of the cylinder : ")), int(input("Enter the length of the cylinder : "))
if (r < 0 or l < 0):
    print("Invalid input")
else:
    area = (2*(3.14159)*(r**2)) + (2*(3.14159)*(r)*(l))
    volume = ((3.14159)*(r**2)*(l))
    print(f"The total surface area of the cylinder is {area : .2f} unit squared and the volume of the cylinder is {volume : .2f} unit cubed")
