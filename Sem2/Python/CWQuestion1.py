mode = 1
marks = []
print('''Enter your marks out of 100 for 5 subjects (for 2023 Even Semester) :''')
for i in range(0, 5):
    inp = int(input(""))
    marks.append(inp)
while (mode):
    print('''You have the following options :
1. Sum of the marks in all the subjects
2. Calculate average marks and percentage
3. Find your grade based on your marks
4. Exit''')
    x = int(input("Enter your choice :\n"))
    sum = 0
    for i in range(0,5):
        sum += marks[i]
    avg = sum/5
    if (x == 4):
        mode = 0
    elif (x == 1):
        print("The sum of the marks is ", sum)
    elif (x == 2):
        print("The average marks scored is ", avg," and percentage marks scored is ", (avg), "%")
    elif (x == 3):
        if (avg >= 85):
            print("Grade obtained : A")
        elif (avg >= 75):
            print("Grade obtained : B")
        elif (avg >= 50):
            print("Grade obtained : C")
        elif (avg >= 30):
            print("Grade obtained : D")
        else:
            print("You have to reappear!")
    else:
        print("Please enter a valid input")