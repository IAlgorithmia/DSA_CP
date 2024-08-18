value = 0
for i in range(1, 8):
    for j in range(i + 1, 8):
        print(i, j)
        value += 1
print(f"The total number of combinations is {value}")
