string = input("Enter the string : ")
substring = input("Enter the substring : ")
len = 0
for i in string:
    len += 1
sublen = 0
for i in substring:
    sublen += 1
check = 0
for i in range(len - sublen + 1):
    for j in range(sublen):
        if (string[i + j] == substring[j]):
            check = 1
        else:
            check = 0
            break;
    if (check == 1):
        print("The substring has been found at the index {} of the string".format(i))
if (check == 0):
        print("The substring isn't there in the given string!");
