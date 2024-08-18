class myclass():
    def __init__(self, value):
        self._value = value
    def show_self(self):
        print(f"The value is {self._value}")
    @property #is se ten_value ek property ki tarah behave krta hai rather than a method
    def ten_value(self):
        return 10 * self._value
    @ten_value.setter #setter ke liye usi class method pe getter lagana necessary hai, else it won't work
    def ten_value(self, new_value):
        self._value = new_value/10
obj = myclass(10)
obj.show_self()
print(obj.ten_value) #ise pata hai getter ke paas jana hai, without @property we would have had to write print(obj.ten_value()) but now we can access ten_value as an attribute
obj.ten_value = 99 #ise pata hai setter ke paas jana hai, possible due to applied setter
print(obj._value)
print(obj.ten_value)