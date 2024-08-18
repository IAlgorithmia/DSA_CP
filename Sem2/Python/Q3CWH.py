from random import randint
mode = 1
choices = ['Snake', 'Water', 'Gun']
thetable = [[0, 1, -1], [-1, 0, 1], [0, -1, 1]]
print("Welcome to the Snake, Water and Gun game!")
while (mode):
    print("You have the following options : ")
    print("1. Snake")
    print("2. Water")
    print("3. Gun")
    print("4. Exit")
    num = int(input("Enter your choice : "))
    if (num == 4):
        print("Nice having you, hope to see you soon!")
        break
    num = num - 1
    userchoice = num
    computerchoice = randint(0, 2)
    print("You have chosen : ", choices[userchoice])
    print("The computer has chosen : ", choices[computerchoice])
    result = thetable[userchoice][computerchoice]
    match (result):
        case 1:
            print("Congratulations, you have won!")
        case 0:
            print("Lucky us, it's a draw!")
        case -1:
            print("The computer has won, better luck next time!")