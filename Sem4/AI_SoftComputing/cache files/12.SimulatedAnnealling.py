import math
import random

# Define the objective function that we want to minimize
def objective_function(x, y):
    return x**2 + y**2

# Simulated Annealing Algorithm
def simulated_annealing(obj_func, initial_state, temperature, cooling_rate, min_temp, max_iterations):
    current_state = initial_state
    best_state = current_state
    current_energy = obj_func(*current_state)
    best_energy = current_energy

    for iteration in range(max_iterations):
        temperature *= cooling_rate

        # Generate a new state
        new_state = (current_state[0] + random.uniform(-1, 1), current_state[1] + random.uniform(-1, 1))
        new_energy = obj_func(*new_state)

        # Acceptance probability
        if new_energy < current_energy or random.random() < math.exp((current_energy - new_energy) / temperature):
            current_state = new_state
            current_energy = new_energy

            if current_energy < best_energy:
                best_state = current_state
                best_energy = current_energy

        if temperature < min_temp:
            break

    return best_state, best_energy

if __name__ == '__main__':
    # Define initial parameters
    initial_state = (5, 5)  # Initial guess for the minimum
    initial_temperature = 100.0
    cooling_rate = 0.95
    min_temperature = 1e-3
    max_iterations = 1000

    # Run the simulated annealing algorithm
    best_state, best_energy = simulated_annealing(objective_function, initial_state, initial_temperature, cooling_rate, min_temperature, max_iterations)

    print(f"Best State: {best_state}")
    print(f"Best Energy: {best_energy}")
