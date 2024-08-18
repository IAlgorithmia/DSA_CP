string = input("Enter the string : ")
lst = []
j = 0
for i in string:
    lst[j:] = [i]
    j += 1
print("The list is ", lst)