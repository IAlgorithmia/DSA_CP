value = int(input("Enter the number of key-value pairs you want to enter : "))
thedict = {}
for i in range(value):
    key = input("Enter the key : ")
    value = input("Enter the value : ")
    thedict[key] = value
keys = list(thedict.keys())
values = list(thedict.values())
minimumvalue = values[0]
maximumvalue = values[0]
minimumkey = keys[0]
maximumkey = keys[0]
for i in values:
    if (i > maximumvalue):
        maximumvalue = i
    if (i < minimumvalue):
        minimumvalue = i
for i in keys:
    if (i > maximumkey):
        maximumkey = i
    if (i < minimumkey):
        minimumkey = i
print(f"The maximum key is {maximumkey} and the mnimum key is {minimumkey}\nThe maximum value is {maximumvalue} and the minimum value is {minimumvalue}")