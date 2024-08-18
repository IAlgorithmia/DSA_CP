m = 0
for i in range(33, 127):
    print(chr(i), end = " ")
    m = m + 1
    if (m == 10):
        print("\n")
        m = 0
