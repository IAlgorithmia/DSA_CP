def findsum(thelist, sum):
    items = []
    for i in thelist:
        for j in thelist[(thelist.index(i) + 1):]:
            if (i + j == sum):
                items.append((i, j))
    if (len(items) == 0):
        return None
    else:
        return items
mylist = [1, 2, -12, 98, 0, -95, 3, 15]
answer = findsum(mylist, 3)
print(answer)