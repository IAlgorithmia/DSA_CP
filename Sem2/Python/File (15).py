def greet(fx):
    def mfx(*args, **kwargs):
        print("Good morning :)")
        fx(*args, **kwargs)
        print("Good night :)")
    return mfx
@greet
def hello():
    print("Hey there, how are you?")
# greet(hello)() Same thing as above
@greet
def add(a, b):
    print(a + b)
# greet(add)(5, 9) Same thing as below
hello()
add(5, 9)