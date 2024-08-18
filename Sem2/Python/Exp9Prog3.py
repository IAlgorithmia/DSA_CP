string = input("Enter the string : ")
string = string.upper()
check = 1
for i in range(65, 91):
    if (chr(i) not in string):
        check = 0
if (check == 1):
    print("It is a pangram!")
else:
    print("It is not a pangram!")

    
