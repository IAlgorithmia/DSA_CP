import turtle

# object tr for turtle
tr = turtle.Turtle()
wn = turtle.Screen()
wn.title("Olympics Rings")
# set thickness for each ring
tr.speed(8)
tr.pensize(5)
tr.shape("turtle")
wn.bgcolor("cyan")

tr.color("blue")
tr.penup()
tr.goto(-110, -25)
tr.pendown()
tr.circle(45)

tr.color("black")
tr.penup()
tr.goto(0, -25)
tr.pendown()
tr.circle(45)

tr.color("red")
tr.penup()
tr.goto(110, -25)
tr.pendown()
tr.circle(45)

tr.color("yellow")
tr.penup()
tr.goto(-55, -75)
tr.pendown()
tr.circle(45)

tr.color("green")
tr.penup()
tr.goto(55, -75)
tr.pendown()
tr.circle(45)
turtle.done()