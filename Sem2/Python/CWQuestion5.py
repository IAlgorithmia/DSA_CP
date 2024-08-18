def sorter(a, b):
    if (a < b):
        a, b = b, a
        #In this way, the first argument is always bigger than the second one
    return a, b
e, f, g, h = 10, 8, 2, 5
print("It originally was {} {} {} {}".format(e, f, g ,h))
e, f = sorter(e, f)
g, h = sorter(g, h)
print("It now is {} {} {} {}".format(e, f, g ,h))