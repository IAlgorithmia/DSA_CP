value = 0
for i in range(1, 10000):
    for j in range(1, i):
        if (i % j == 0):
            value += j
    if (value == i):
        print(f"{i} is a perfect number")
    value = 0
