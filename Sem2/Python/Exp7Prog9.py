thelist = []
value = 0
num1 = int(input("Enter how many dictionaries you want to enter : "))
for i in range(num1):
    thedict = {}
    num2 = int(input(f"Enter how many elements you want to have in dictionary {i + 1} : "))
    for j in range(num2):
        value = input("Enter the key value pairs : ")
        if value.isspace():
            thedict[""] = ""
        else:
            thedict[a] = b
    thelist.append(thedict)
print(thelist)
