import turtle

t = turtle.Turtle()
s = turtle.Screen()

s.bgcolor("blue")
s.title("Pentagon")
t.speed(3)
t.pensize(4)
t.penup()
t.shape("turtle")

colors = ["red", "purple", "yellow", "green", "cyan"]
i = 0

t.goto(0, -200)
t.pendown()
t.goto(-190,-62)
t.goto(-118,162)
t.goto(118,162)
t.goto(190,-62)
t.goto(0, -200)

i = 0
t.color("black")

t.fillcolor(colors[i])
i += 1
t.begin_fill()
t.goto(0, 0)
t.goto(-190, -62)
t.end_fill()

t.fillcolor(colors[i])
i += 1
t.begin_fill()
t.goto(0, 0)
t.goto(-118,162)
t.end_fill()

t.fillcolor(colors[i])
i += 1
t.begin_fill()
t.goto(0, 0)
t.goto(118,162)
t.end_fill()

t.fillcolor(colors[i])
i += 1
t.begin_fill()
t.goto(0, 0)
t.goto(190,-62)
t.end_fill()

t.fillcolor(colors[i])
i += 1
t.begin_fill()
t.goto(0, 0)
t.goto(0,-200)
t.end_fill()

turtle.done()