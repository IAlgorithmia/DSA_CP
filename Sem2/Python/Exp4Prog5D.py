k = 5
for i in range(1, 7):
    for j in range(1, k):

        print(j, end = " ")
    print("\n")
    if (i < 3):
        print("\n")
    if (i > 2):
        k -= 1