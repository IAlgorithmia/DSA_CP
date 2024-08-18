class Checker:
    def __init__(self):
        self.opening = {'(' : ')', '{' : '}', '[' : ']'}
    def check(self, expression):
        stack = []
        opening = 0
        closing = 0
        for i in expression:
            if i in self.opening:
                stack.append(self.opening[i])
                opening += 1
                continue
            else:
                try:
                    if (i != stack.pop()):
                        return 0
                    closing += 1
                except:
                    return 0
        if (opening != closing):
            return 0
        return 1
object = Checker()
value = object.check("{{{")
if (value == 1):
    print("The input expression is correct")
else:
    print("The input expression is not correct")