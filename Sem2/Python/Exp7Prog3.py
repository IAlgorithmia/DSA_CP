def compare(list1, list2):
    see = 0
    for i in list1:
        for j in list2:
            if (i == j):
                see = 1
                return True
    return False
list1 = input("Enter the list 1 : ").split()
list2 = input("Enter the list 2 : ").split()
ans = compare(list1, list2)
print("The returned answer is", ans)
