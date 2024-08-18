lst = []
j = 0
for i in range(1, 11):
    if (i < 6):
        lst[j:] = [i*i]
        j += 1
    else:
        lst[j:] = [(i + 20)*(i + 20)]
        j += 1
print("The resulting list is :", lst)
