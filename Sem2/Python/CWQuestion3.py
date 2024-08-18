dict1 = {}
string = input("Enter the string\n")
for i in string:
    if (i in dict1):
        dict1[i] += 1
    else:
        dict1[i] = 1
for i in dict1:
    print(f"{i} appears {dict1[i]} times in the string!")