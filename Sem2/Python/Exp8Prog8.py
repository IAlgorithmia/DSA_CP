print("Enter the data below! (Number of keys and values should be same!)")
listkeys = input("Enter the keys for the dictionary : ").split()
listvalues = input("Enter the values for the dictionary : ").split()
thedict = {}
for i, j in zip(listkeys, listvalues):
    thedict[i] = {int(j)}
print(f"The formed dictionary is : {thedict}")