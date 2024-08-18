class Demo:
    print(1)
    def __init__(self):
        print(2)
        self.x = 1
    def change(self):
        print(3)
        self.x = 10
    print(4)
class B(Demo):
    print(5)
    def change(self):
        print(6)
        self.x = self.x + 1
        return self.x
    print(7)
def main():
    print(8)
    obj = B()
    print(9)
    print(obj.change())
print(10)
main()