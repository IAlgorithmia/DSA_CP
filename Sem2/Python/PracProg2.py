today, days = int(input("Enter number for today's day (Sunday is 0) : ")), int(input("Enter the desired number of days after today : "))
thedays = ["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"]
ans = today + days + 1
while (ans > 6):
    ans = ans - 7
if (days == 0):
    print(f"Today is {thedays[today]}. The day after {days} days from today will be {thedays[today]}")
else:
    print(f"Today is {thedays[today]}. The day after {days} days from today will be {thedays[ans]}")
