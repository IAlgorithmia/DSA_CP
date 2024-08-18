# This is just good enough

import turtle 

t = turtle.Turtle()

t.penup()
t.goto(0, -400)
t.pensize(4)
t.speed(0)
t.shape("turtle")


t.pendown()
t.color("red")
for i in range(9):
    t.circle(300, 20)
    t.right(90)
    t.forward(65)
    t.left(90)
    t.forward(65)
    t.left(90)
    t.forward(65)
    t.right(90)
    t.circle(300, 20)

t.penup()
t.goto(0, -300)
t.pendown()
t.color("black")
t.circle(300)

t.penup()
t.goto(-250, 100)
t.color("red")
t.write("NIT Kurukshetra", font = ("Verdana", 40, "bold"))

t.penup()
t.color("black")
t.goto(-250, 50)
t.write("Institution of national inportance", font = ("Verdana", 20, "bold"))

# Draw the arrow
t.penup()
t.goto(0, -190)
t.fillcolor("red")
t.begin_fill()
t.pendown()
t.left(90)
t.forward(100)  # Move forward by 100 units
t.right(90)  # Turn right by 90 degrees
t.forward(30)  # Move forward by 50 units
t.left(120)  # Turn left by 120 degrees
t.forward(100)  # Move forward by 100 units
t.left(120)  # Turn left by 120 degrees
t.forward(100)  # Move forward by 100 units
t.left(120)  # Turn left by 120 degrees
t.forward(30)
t.right(90)# Move forward by 50 units
t.forward(100)
t.left(90)
t.forward(35)
t.end_fill()

t.fillcolor("red")
t.begin_fill()
t.penup()
t.goto(-25, -130)
t.pendown()
t.circle(60, 40)
t.right(90)
t.forward(20)
t.right(90)
t.circle(-70, 80)
t.right(90)
t.forward(20)
t.right(90)
t.circle(60, 40)
t.end_fill()
# t.forward()

turtle.done()