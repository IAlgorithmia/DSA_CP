a = (input("Enter the number : "))
print(f"The multiplication table of {(a)} is : ")
try:
    for i in range(1, 11):
        print(f"{int(a)} X {i} = {int(a) * i}")
except Exception as e: #Although there's no need to write exception as e we can simply continue
    print("Invalid Input!")
    print(f"The actual error thrown by the compiler is {e}")
print("Some lines of code")
print("Some more lines of code")

a = (input("Enter the numbers you want to be a part of the list : ")).split()
print(f"The list is {a}")
place = (input("Enter the index whose element you want to know : "))
try:
    print(f"The element at index {int(place)} is {a[int(place)]}")
except ValueError:
    print("This is a value error. Please enter a number!")
except IndexError:
    print("This is an index error. Please enter an index that is in range of the list!")