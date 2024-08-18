let a = prompt("Enter youe age : ")
//prompt converts any number to string
a = Number.parseInt(a)
// parseInt is a function of module Number that converts string to number  
console.log(a, typeof(a))
if (a < 0)
{
    alert("Enter a valid age!")
}
else if (a < 9)
{
    alert("You're a kid and can't even think of driving!")
}
else if (a >= 9 && a < 18)
{
    alert("You're gonna be able to drive after 18")
}
else
{
    alert("Now you're an adult and are eligible for driving!")
}

//Enter afghanistan

let gender = prompt("Enter your gender : ")
console.log("You can", (gender == "Male" ? "Drive" : "not Drive"))