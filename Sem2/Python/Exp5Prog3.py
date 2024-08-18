def bubblesorter(list, len):
    passno = 1
    for i in range(len - passno):
        if list[i] > list[i + 1]:
            list[i], list[i + 1] = list[i + 1], list[i]
        passno += 1
string1 = input("Enter the lowercase string 1 : ")
string2 = input("Enter the lowercase string 2 : ")
list = []
k = 0
for i in string1 : 
    for j in string2 :
        if (i == j and i not in list):
            list[k:] = [i]
            k += 1
            break
len = 0
for i in list:
    len += 1
if (len != 0):
    for i in range(0, len):
        list[i] = ord(list[i])
    bubblesorter(list, len)
    for i in range(0, len):
        list[i] = chr(list[i])
    print("The common characters in the two strings in lexocographical order are : ", list)
else:
    print("There are no common characters!")