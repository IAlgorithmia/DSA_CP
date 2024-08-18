vals = 0
num = int(input("Enter how many tuples you want to store : "))
list1 = []
for i in range(num):
    vals = tuple(input("Enter the two numbers : ").split())
    list1.append(vals)
myset = set()
for i in list1:
    for j in i:
        myset.add(j)
myset = sorted(myset)
print(myset)

