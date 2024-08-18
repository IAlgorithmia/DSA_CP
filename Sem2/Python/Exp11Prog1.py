class Converter:
    def __init__(self):
        self.roman_values = {"I":1, "V":5, "X":10, "L":50, "C":100, "D":500, "M":1000}
    def convert(self, expression):
        prev = 0
        sum = 0
        expression = expression[::-1]
        #The roman numeral experssion are evaluated in the reverse order
        for i in expression:
            if (self.roman_values[i] < prev):
                sum = abs(sum - self.roman_values[i])
            else:
                sum = sum + self.roman_values[i]
            prev = self.roman_values[i]
        return sum

obj = Converter()
value = obj.convert("MCMLXXIV")
print(value)