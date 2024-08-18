thelist = []
num = int(input("Enter the number till which you want the prime numbers : "))
root = int(num**(1/2))
for i in range(2, root):
    check = 1
    for j in range(2, i):
        if (i % j == 0):
            check = 0
            break
    if (check == 1):
        thelist.append(i)
# Now thelist has all the prime numbers under square root of num
for i in thelist:
    print(i, end = ", ")
for i in range(thelist[-1] + 1, num + 1):
    check = 1
    for j in thelist:
        if (i % j == 0):
            check = 0
            break
    if (check == 1):
        print(i, end = ", ")