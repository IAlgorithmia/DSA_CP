num = int(input("Enter the number to which you want to go : "))
thedict = {}
for i in range(1, num + 1):
    thedict[i] = i*i
print("The dictionary is :", thedict)