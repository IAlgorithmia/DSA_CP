num = int(input("Enter the number of your choice : "))
sum = 0
for i in range(2, num):
    check = 0
    for j in range(2, i):
        if (i % j == 0):
            check = 1
            break
    if (check == 0):
        sum += i
print("The sum of all prime numbers less of equal to the given number is %d" % (sum))