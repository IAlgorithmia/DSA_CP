def operate(a, b, choice):
    match choice:
        case 1: 
            return a + b
        case 2:
            return a*b
        case 3:
            if (b != 0):
                return a / b
            else:
                print("The divisor can't be 0")
        case 4:
            if (b != 0):
                return a % b
            else:
                print("The denominator can't be 0")
        case 5:
            return a - b
        case _:
            print("Invalid input!")
print('''Welcome to the Calculator!
Your choices are as follows : 
1. Addition
2. Multiplication
3. Division
4. Modulo
5. Subtraction''')
val1, val2, choice = input("Enter the two operands and the choice : ").split()
val1 = int(val1)
val2 = int(val2)
choice = int(choice)
answer = operate(val1, val2, choice)
if (answer != None):
    print(f"The answer is {answer}")