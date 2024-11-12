#FOR PERFORMING THE Z TEST

from scipy.stats import norm
import math
import numpy as np
from scipy.stats import norm

sample_mean = 110
population_mean = 100
population_std = 15
sample_size = 50
alpha = 0.05

z_score = (sample_mean - population_mean) / (population_std / math.sqrt(sample_size))

critical_value = norm.ppf(1 - alpha/2)

print('\n')

print(f"Z-score: {z_score}")
print(f"Critical Z-value: {critical_value}")

if abs(z_score) > critical_value:
    print("Reject the null hypothesis (H0)")
else:
    print("Fail to reject the null hypothesis (H0)")


#WITH CREATION OF THE SAMPLE DATA

np.random.seed(0)
print('\n')

population_mean = np.random.uniform(50, 100)
population_std_dev = np.random.uniform(5, 15)
sample_size = np.random.randint(20, 101)
alpha = np.random.uniform(0.01, 0.10)

sample_data = np.random.normal(loc=population_mean, scale=population_std_dev, size=sample_size)
sample_data = np.clip(sample_data, 0, 100)
sample_data = np.round(sample_data, 2)

sample_mean = np.mean(sample_data)
standard_error = population_std_dev / np.sqrt(sample_size)
z_score = (sample_mean - population_mean) / standard_error

z_critical = norm.ppf(1 - alpha / 2)
reject_null = abs(z_score) > z_critical

print(f"Sample Data: {sample_data}")
print(f"Sample Mean: {sample_mean:.2f}")
print(f"Population Mean: {population_mean:.2f}")
print(f"Population Std Dev: {population_std_dev:.2f}")
print(f"Sample Size: {sample_size}")
print(f"Alpha: {alpha:.2f}")
print(f"Calculated Z-Score: {z_score:.2f}")
print(f"Critical Z-Value: ±{z_critical:.2f}")
print(f"Reject the null hypothesis? {reject_null}")