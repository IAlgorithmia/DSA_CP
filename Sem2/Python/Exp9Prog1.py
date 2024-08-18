string = input("Enter the string : ")
capital = 0
small = 0
for i in string:
    if (ord(i) > 64 and ord(i) < 91):
        capital += 1
    elif (ord(i) > 94 and ord(i) < 123):
        small += 1
print(f"The number of small letters {small} and capital letters {capital}")
