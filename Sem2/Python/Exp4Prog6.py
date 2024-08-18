for i in range(0, 7):
    for j in range((2*(7 - i)) - 2, 0, -2):
        print("   ", end = "")
    for k in range(i - 1):
        print("{:2d}".format(2**k), end = " ")
    for l in range(i - 1, -1, -1):
        print("{:2d}".format(2**l), end = " ")
    print("\n")
    