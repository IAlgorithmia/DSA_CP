class modifier:
    def __init__(self, value):
        self.value = value
    def __add__(self, other):
        print(f"You're trying to add {self.value} with {other.value}")
        return self.value + other.value
    def __sub__(self, other):
        print(f"You're trying to subtract {self.value} with {other.value}")
        return self.value - other.value
    def __mul__(self, other):
        print(f"You're trying to multiply {self.value} with {other.value}")
        return self.value * other.value
    def __str__(self, other):
        print(f"You're trying to print {self.value} with {other.value}")
        return "Hey"
a = modifier(5)
b = modifier(6)
print(a+b)
print(a-b)
print(a*b)
a.__str__(b)