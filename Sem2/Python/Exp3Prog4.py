num, days = input("Enter today's day number (0 means Sunday) and desired number of days after today : ").split()
num = int(num)
days = int(days)
ans = num + days + 1
while (ans > 6):
    ans = ans - 7
data = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"]
print("The desired day is : ", data[ans])
