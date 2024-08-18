import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

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

def backward_propagation(inputs, outputs, hidden_layer_output, output_layer_output, input_hidden_weights, hidden_output_weights, learning_rate):
    output_error = outputs - output_layer_output
    output_delta = output_error * sigmoid_derivative(output_layer_output)

    hidden_error = output_delta.dot(hidden_output_weights.T)
    hidden_delta = hidden_error * sigmoid_derivative(hidden_layer_output)

    hidden_output_weights += hidden_layer_output.T.dot(output_delta) * learning_rate
    input_hidden_weights += inputs.T.dot(hidden_delta) * learning_rate

def train_neural_network(inputs, outputs, hidden_size, epochs, learning_rate):
    input_size = inputs.shape[1]
    output_size = outputs.shape[1]

    input_hidden_weights, hidden_output_weights = initialize_weights(input_size, hidden_size, output_size)

    for epoch in range(epochs):
        hidden_layer_output, output_layer_output = forward_propagation(inputs, input_hidden_weights, hidden_output_weights)

        backward_propagation(inputs, outputs, hidden_layer_output, output_layer_output, input_hidden_weights, hidden_output_weights, learning_rate)

        if epoch % 1000 == 0:
            loss = np.mean(np.abs(outputs - output_layer_output))
            print(f"Epoch: {epoch}, Loss: {loss}")

    return input_hidden_weights, hidden_output_weights

def predict(inputs, input_hidden_weights, hidden_output_weights):
    _, output = forward_propagation(inputs, input_hidden_weights, hidden_output_weights)
    return np.round(output)

# XOR function dataset
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
outputs_xor = np.array([[0], [1], [1], [0]])

# Train the neural network
hidden_size = 4
epochs = 10000
learning_rate = 0.1
input_hidden_weights, hidden_output_weights = train_neural_network(inputs, outputs_xor, hidden_size, epochs, learning_rate)

# Test the trained network
predictions = predict(inputs, input_hidden_weights, hidden_output_weights)
print("\nPredictions after training:")
print(predictions)
