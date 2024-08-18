value = int(input("Enter the number of key-value pairs you want to enter : "))
thedict = {}
for i in range(value):
    key = input("Enter the key : ")
    value = input("Enter the value : ")
    thedict[key] = value
num = input("Enter the item you want to search in the dictionary as a key : ")
ans = num in thedict.keys()
if (ans):
    print(f"{num} is present in the dictionary as a key")
else:
    print(f"{num} is not present in the dictionary as a key")
