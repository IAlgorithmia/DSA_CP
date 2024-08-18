days = {1:"Monday", 2:"Tuesday", 3:"Wednesday", 4:"Thursday", 5:"Friday", 6:"Saturday", 7:"Sunday"}
day = int(input("Enter the day : "))
month = int(input("Enter the month : "))
year = int(input("Enter the year : "))
value = day + month + year - 2

print(f"The day is {days[value]}")