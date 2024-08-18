globalvar = 21
def function():
    variable1 = 0
    variable2 = 9
    variable3 = 5
    variable8 = 33
    variable2 = 12
print(f"The number of local variables in the function is {function.__code__.co_nlocals}")
