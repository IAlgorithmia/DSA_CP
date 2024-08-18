string = input("Enter the string : ")
dict = {}
for i in string:
    if (i not in dict):
        dict[i] = 1
    else:
        dict[i] += 1
string1 = ""
string2 = ""
for i in dict:
    if (dict[i] == 1):
        string1 += i
    else:
        string2 += i
print("The first string (singly occuring characters) is : ", string1)
print("The first string (doubly occuring characters) is : ", string2)