import numpy as np

def threshold(x):
    return 1 if x >= 0 else 0

def initialize_weights(input_size):
    return np.random.uniform(size=input_size)

def train_perceptron(inputs, targets, weights, learning_rate, epochs):
    for epoch in range(epochs):
        for input_data, target in zip(inputs, targets):
            prediction = threshold(np.dot(input_data, weights))
            error = target - prediction
            weights += learning_rate * error * input_data

        if epoch % 100 == 0:
            accuracy = evaluate(inputs, targets, weights)
            print(f"Epoch: {epoch}, Accuracy: {accuracy}%")

    return weights

def evaluate(inputs, targets, weights):
    predictions = [threshold(np.dot(input_data, weights)) for input_data in inputs]
    correct_predictions = np.sum(predictions == targets)
    accuracy = (correct_predictions / len(targets)) * 100
    return accuracy

# ANDNOT function dataset
inputs = np.array([[0, 0], [0, 1], [1, 0], [1, 1]])
targets_andnot = np.array([0, 1, 0, 0])

# Initialize weights
input_size = inputs.shape[1]
weights = initialize_weights(input_size)

# Set learning rate and number of epochs
learning_rate = 0.1
epochs = 1000

# Train the perceptron
trained_weights = train_perceptron(inputs, targets_andnot, weights, learning_rate, epochs)

# Evaluate the trained perceptron
accuracy = evaluate(inputs, targets_andnot, trained_weights)
print("\nTrained Weights:", trained_weights)
print("Accuracy on training data:", accuracy, "%")

# Make predictions
predictions = [threshold(np.dot(input_data, trained_weights)) for input_data in inputs]
print("\nPredictions:")
print(predictions)
