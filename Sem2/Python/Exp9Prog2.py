string = input("Enter the string : ")
check = 1
len = 0
for i in string:
    len += 1
for i in range(len):
    if (string[i] != string[len - 1 - i]):
        check = 0
        break
if (check == 0):
    print("This is not a plaindrome!")
else:
    print("This is a plaindrome!")
