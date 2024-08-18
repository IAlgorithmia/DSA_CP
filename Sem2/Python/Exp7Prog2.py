data = input("Enter the elements of the list to be examined : ").split()
count = 0
for i in data:
    if (len(i) >= 2 and i[0] == i[len(i) - 1]):
        count += 1
print("The number of strings with given conditions is :",count)
