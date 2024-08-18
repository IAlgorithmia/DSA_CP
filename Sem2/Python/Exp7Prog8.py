num = int(input("Enter how many tuples you want to add : "))
list1 = []
for i in range(num):
    val = tuple(input("Enter the tuple : ").split())
    list1.append(val)
print(list1)
minimum = list1[0][1]
thattuple = 0
for i in list1:
    if (len(i) > 1 and minimum > i[1]):
        minimum = i[1]
        thattuple = i
print(f"The smallest second index element among all the tuples is : {minimum} and the tuple having this item is {thattuple}")
