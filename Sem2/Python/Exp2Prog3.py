num = int(input("Enter a 4 digit number : "))
dig = []
for i in range(4):
    x = num % 10
    dig.append(x)
    num = num // 10
print("The reversed number is : ")
for i in range(4):
    print(dig[i], end = "")
