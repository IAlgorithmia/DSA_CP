import time
import turtle
a='AM'
t=turtle.Turtle()
t1=turtle.Turtle()
s=turtle.Screen()
s.bgcolor('black')
sec=20
min=36
hour=12
t1.pensize(3)
t1.color('yellow')
t1.up()
t1.goto(-30,0)
t1.down()
for i in range(2):
    t1.forward(200)
    t1.lt(90)
    t1.fd(40)
    t1.lt(90)
t1.hideturtle()
while True:
    t.hideturtle()
    t.color("white")
    t.clear()
    t.write(str(hour).zfill(2)+":"+str(min).zfill(2)+":"+str(sec).zfill(2)+a,font=("arial narrow",22,"bold"))
    time.sleep(1)
    sec=sec+1
    if(sec==60):
        sec=0
        min=min+1
    if(min==60):
        min=0
        hour=hour+1
    if(hour==13):
        hour=1
    if(hour<12):
        a="AM"
    else:
        a="PM"