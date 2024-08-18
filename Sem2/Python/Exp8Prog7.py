num = int(input("Enter the number of dictionaries you want to enter : "))
thelist = []
for i in range(num):
    value = int(input(f"Enter the number of key-value pairs you want to enter in dictionary {i + 1}: "))
    thedict = {}
    for i in range(value):
        key = input("Enter the key : ")
        value = input("Enter the value : ")
        thedict[key] = value
    thelist.append(thedict)
thekey = input("Enter the key you want to search for : ")
thevalue = input("Enter the value you want to search for : ")
answer = 0
for i in thelist:
    if thekey in i:
        if (i[thekey] == thevalue):
            answer += 1
print(f"The key {thekey} occurs in the data {answer} times with the value {thevalue}")