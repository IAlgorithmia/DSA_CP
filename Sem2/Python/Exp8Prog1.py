values = input("Enter the number of elements you want in the tuple : ").split()
values = tuple(values)
elem = input("Enter the element you want to search for in the tuple : ")
print(values)
check = 0
for index, item in enumerate(values):
    if (item == elem):
        print(f"The element has been found at position {index + 1} of the tuple")
        check = 1
        break
if (check == 0):
    print("The item couldn't be found in the tuple")
    
    
