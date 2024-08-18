class Math:
    def __init__(self, num):
        self.num = num
    def addtonum(self, n):
        self.num += n
    @staticmethod #Makes the method usable by the class objects diretly
    def add(a, b):
        print("Their sum is", a + b)
a = Math(66)
print(a.num)
a.addtonum(7)
print(a.num)
a.add(5, 9)