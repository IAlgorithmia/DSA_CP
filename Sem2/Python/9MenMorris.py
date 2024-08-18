import turtle

def coordinate(x):
    newlist = [(x, x), (x, 0), (x, -x), (0, -x), (-x, -x), (-x, 0), (-x, x), (0, x)]
    return newlist

t = turtle.Turtle()
s = turtle.Screen()
t.shape("turtle")
s.bgcolor("cyan")
t.pensize(5)
t.speed(5)

t.penup()
t.goto(-400, -400)
t.pendown()
t.goto(-400, 400)
t.goto(400, 400)
t.goto(400, -400)
t.goto(-400, -400)

t.penup()
t.goto(-300, -300)
t.pendown()
t.goto(-300, 300)
t.goto(300, 300)
t.goto(300, -300)
t.goto(-300, -300)

t.penup()
t.goto(-200, -200)
t.pendown()
t.goto(-200, 200)
t.goto(200, 200)
t.goto(200, -200)
t.goto(-200, -200)

t.penup()
t.goto(0, 200)
t.pendown()
t.goto(0, 400)

t.penup()
t.goto(-200, 0)
t.pendown()
t.goto(-400, 0)

t.penup()
t.goto(0, -200)
t.pendown()
t.goto(0, -400)

t.penup()
t.goto(200, 0)
t.pendown()
t.goto(400, 0)

t.pensize(15)

coords1 = coordinate(200)
for i in coords1:
    t.penup()
    t.goto(i)
    t.pendown()
    t.circle(7)
    
coords1 = coordinate(300)
for i in coords1:
    t.penup()
    t.goto(i)
    t.pendown()
    t.circle(7)
    
coords1 = coordinate(400)
for i in coords1:
    t.penup()
    t.goto(i)
    t.pendown()
    t.circle(7)

turtle.done()