import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def initialize_weights(input_size, hidden_size, output_size):
    input_hidden_weights = np.random.uniform(size=(input_size, hidden_size))
    hidden_output_weights = np.random.uniform(size=(hidden_size, output_size))
    return input_hidden_weights, hidden_output_weights

def forward_propagation(inputs, input_hidden_weights, hidden_output_weights):
    hidden_layer_input = np.dot(inputs, input_hidden_weights)
    hidden_layer_output = sigmoid(hidden_layer_input)

    output_layer_input = np.dot(hidden_layer_output, hidden_output_weights)
    output_layer_output = sigmoid(output_layer_input)

    return hidden_layer_output, output_layer_output

def three_layer_ann(inputs, input_hidden_weights, hidden_output_weights):
    hidden_layer_output, output_layer_output = forward_propagation(inputs, input_hidden_weights, hidden_output_weights)
    return output_layer_output

# Example usage
input_size = 3  # Number of input features
hidden_size = 5  # Number of neurons in the hidden layer
output_size = 4  # Number of neurons in the output layer

# Randomly initialize weights
input_hidden_weights, hidden_output_weights = initialize_weights(input_size, hidden_size, output_size)

# Example input data
input_data = np.array([[0.2, 0.4, 0.6], [0.1, 0.3, 0.5]])

# Forward propagation through the three-layer ANN
output = three_layer_ann(input_data, input_hidden_weights, hidden_output_weights)

print("Output of the three-layer ANN:")
print(output)
