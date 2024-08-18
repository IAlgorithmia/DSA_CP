num1 = int(input("Enter the number of tuples you want to enter into the list : "))
thelist = []
for i in range(num1):
    templist = []
    val = int(input(f"Enter how many elements you want to enter in tuple {i + 1} : "))
    for i in range(val):
        elem = input("Enter the element : ")
        templist.append(elem)
    thelist.append(tuple(templist))
print(thelist)
anotherlist = []
for i in thelist:
    if (len(i) != 0):
        anotherlist.append(i)
