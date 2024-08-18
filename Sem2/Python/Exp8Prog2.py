num = int(input("Enter the number of tuple you want to enter into the list : "))
thelist = []
for i in range(num):
    values = input("Enter the items for the tuple : ").split()
    values = tuple(values)
    thelist.append(values)
for i in range(len(thelist)):
    thelist[i] = list(thelist[i])
for i in thelist:
    print(i)
