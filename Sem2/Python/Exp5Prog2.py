string = input("Enter the string : ")
lst = []
j = 0
start = 0
len = 0
for i in string:
    len += 1
for i in range(0, len):
    if (string[i] == ' '):
        lst[j:] = [string[start:i]]
        start = i
        j += 1
    if (i == len - 1):
        lst[j:] = [string[start:i + 1]]
dictionary = {}
for i in lst:
    if i in dictionary:
        print(f"'{i}' is the first repeated word")
        break
    else:
        dictionary[i] = 1