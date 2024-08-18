for i in range(1, 7):
    for k in range(6 - i, 0, -1):
        print("  ", end = "")
    for j in range(i, 0, -1):
        print(j, end = " ")
    print("\n")
    if (i < 3):
        print("\n")