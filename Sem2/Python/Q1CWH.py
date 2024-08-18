import time
hours = int(time.strftime('%H'))
minutes = int(time.strftime('%M'))
seconds = int(time.strftime('%S'))
'''
1PM to 5PM - Afternoon
5PM to 7PM - Evening
7PM to 4AM - Night
4AM to 1 PM - Morning
'''
print(hours)
if (hours >= 4 and hours <13):
    print("Good morning sire!")
elif (hours >= 13 and hours <17):
    print("Good afternoon sire!")
elif (hours >= 19 or hours < 4):
    print("Good night sire!")
else:
    print("Good evening sire!")