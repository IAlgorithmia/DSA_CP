lst = input("Enter the elements of the list : ").split()
len = 0
for i in lst:
    len += 1
for i in range(len):
    lst[i] = int(lst[i])
print("The list is", lst)
ans = 1
for i in range(len):
    ans *= lst[i]
print("The result after multiplying all the items of the list is :", ans)
