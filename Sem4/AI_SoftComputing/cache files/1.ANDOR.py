import numpy as np
inputs = int(input("Enter the number of Inputs : "))
rows = int(input("Enter the number of Rows : "))

user_inputs = [[int(x) for x in input(f'Enter values for the {inputs} inputs for row {i + 1} (separated by space): ').split()] for i in range(rows)]

std_inputs = np.ones(inputs)

dot_products = np.array([std_inputs @ i for i in user_inputs])

print("\nOR Results : \n")

for i in dot_products:
    i = int(i)
    if (i >= 1):
        print("Activation : " + "1")
    else:
        print("Activation : " + "0")

print("\nAND Results : \n")

for i in dot_products:
    if (i >= inputs):
        print("Activation : " + "1")
    else:
        print("Activation : " + "0")
        
# An activation function is a mathematical function that controls the output of a neural network. Activation functions help in determining whether a neuron is to be fired or not.