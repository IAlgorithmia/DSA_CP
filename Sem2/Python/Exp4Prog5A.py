for i in range(1, 7):
    for j in range(1, i + 1):            
        print(f"{j} ", end = "")
        if (i == 5 and j == 1):
            print("  ", end = "")
    print("\n")
