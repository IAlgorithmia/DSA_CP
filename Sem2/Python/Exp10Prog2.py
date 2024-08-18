import turtle

radii = []
for i in range(5):
    num = int(input("Enter the radius of the circle you want : "))
    radii.append((0, -num))

s = turtle.Screen()
t = turtle.Turtle()

colors = ["red", "purple", "yellow", "green", "black"]

t.pensize(5)
s.title("Circles with same radius")
s.bgcolor("blue")
t.speed(10)
t.shape("turtle")

for i in range(5):
    t.penup()
    t.goto(radii[i])
    t.color(colors[i])
    t.pendown()
    t.circle(-radii[i][1])

t.penup()
t.goto(0, 0)
t.pensize(15)
t.pendown()
t.color("orange")
t.circle(1)
t.hideturtle()
turtle.done()