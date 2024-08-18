list1 = input("Enter the list 1 items seperated by spaces : ").split()
list2 = input("Enter the list 2 items seperated by spaces : ").split()
list1 = list1*2
len1 = len(list1)
len2 = len(list2)
checker = 0
for i in range(len2):
    if (list2 == list1[i:i+len2]):
        checker = 1
if (checker == 1):
    print("The two lists are circularly identical!")
else:
    print("The two lists are not circularly identical!")
