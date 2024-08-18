m = 0
for i in range(100, 1001):
    if (i % 5 == 0 and i % 6 == 0):
        print(i, end = " ")
        m = m + 1
        if (m == 10):
            print("\n")
            m = 0
