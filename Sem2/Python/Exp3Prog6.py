month, year = input("Enter the month and year in numbers : ").split()
month = int(month)
year = int(year)
dict1 = {1 : 31, 2 : 28, 3 : 31, 4: 30, 5: 31, 6: 30, 7 : 31, 8 : 31, 9 : 30, 10 : 31, 11 : 30, 12 : 31}
dict2 = {1 : 31, 2 : 29, 3 : 31, 4: 30, 5: 31, 6: 30, 7 : 31, 8 : 31, 9 : 30, 10 : 31, 11 : 30, 12 : 31}
dict3 = {1 : "January", 2 : "February", 3 : "March", 4 : "April", 5 : "May", 6 : "June", 7 : "July", 8 : "August", 9 : "September", 10 : "October", 11 : "November", 12 : "December"}
if (year % 400 == 0 or (year % 100 != 0 and year % 4 == 0)):
    print("{} {} has {} days" .format(dict3[month], year, dict2[month]))
else:
    print("{} {} has {} days" .format(dict3[month], year, dict1[month]))