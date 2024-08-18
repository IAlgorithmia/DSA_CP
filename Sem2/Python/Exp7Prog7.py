list1 = input("Enter the list 1 : ").split()
list2 = input("Enter the list 2 : ").split()
length = len(list1)
dict = {}
list = []
for i in range(length):
    dict["color_name"] = list1[i]
    dict["color_code"] = list2[i]
    list.append(dict)
    dict = {}
print("The resultant list of dictionaries is :\n", list)
