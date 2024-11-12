import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import PolynomialFeatures, StandardScaler
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error

def generate_polynomial_features(X, degree):
    poly = PolynomialFeatures(degree=degree)
    return poly.fit_transform(X)

def gradient_descent(X, y, learning_rate=0.001, iterations=1000):
    m, n = X.shape
    theta = np.zeros(n)
    cost_history = np.zeros(iterations)

    for it in range(iterations):
        prediction = X.dot(theta)
        errors = prediction - y
        gradient = (1/m) * X.T.dot(errors)
        theta -= learning_rate * gradient
        cost_history[it] = (1/(2*m)) * np.sum(np.clip(errors**2, -1e10, 1e10))

    return theta, cost_history

def plot_cost_history(cost_history):
    plt.plot(cost_history)
    plt.title("Cost Function vs. Iterations")
    plt.xlabel("Iterations")
    plt.ylabel("Cost")
    plt.show()

def generate_synthetic_data(min_val, max_val, num_points):
    X = np.linspace(min_val, max_val, num_points).reshape(-1, 1)

    y = 4 + 3 * X + X**2 + np.random.randn(num_points, 1) * 5
    return X, y.ravel()

def run_gradient_descent(X, y, degree, learning_rate=0.001, iterations=1000):
    X_poly = generate_polynomial_features(X, degree)
    theta, cost_history = gradient_descent(X_poly, y, learning_rate, iterations)
    return theta, cost_history

def test_polynomial_regression():

    min_val = float(input("Enter the minimum value for the input variable range: "))
    max_val = float(input("Enter the maximum value for the input variable range: "))
    num_points = int(input("Enter the number of data points: "))


    degree = int(input("Enter the degree of the polynomial function: "))
    learning_rate = float(input("Enter the learning rate for Gradient Descent: "))
    iterations = int(input("Enter the number of iterations: "))


    X, y = generate_synthetic_data(min_val, max_val, num_points)


    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)


    scaler = StandardScaler()
    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)


    theta, cost_history = run_gradient_descent(X_train_scaled, y_train, degree, learning_rate, iterations)


    plot_cost_history(cost_history)


    X_test_poly = generate_polynomial_features(X_test_scaled, degree)
    y_pred = X_test_poly.dot(theta)


    test_error = mean_squared_error(y_test, y_pred)
    print(f"Test Mean Squared Error: {test_error}")


    X_fit = np.linspace(min_val, max_val, 100).reshape(-1, 1)
    X_fit_scaled = scaler.transform(X_fit) 
    X_fit_poly = generate_polynomial_features(X_fit_scaled, degree)
    y_fit = X_fit_poly.dot(theta)


    plt.scatter(X_test, y_test, color="blue", label="Original Data")
    plt.plot(X_fit, y_fit, color="red", label=f"Degree {degree} Polynomial Curve")
    plt.xlabel("Input Variable")
    plt.ylabel("Target Variable")
    plt.title(f"Polynomial Regression of Degree {degree}")
    plt.legend()
    plt.show()

test_polynomial_regression()
