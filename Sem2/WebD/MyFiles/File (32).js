console.log(document) //Makes the whole document as js object
document.body.style.background = "black" 
// location.href = "https://www.twitter.com" this takes the page to the given website
let age = prompt("Enter your age : ")
age = Number.parseInt(age)
if (age <= 0)
{
    console.error("Valid age not entered!")
}
else
{
    alert(`Your age is : ${age}, and based on this, you can ${age > 18 ? 'surely drive' : 'cannot drive'}`)
}
let choice = confirm("Do you want to see the prompt again? ")

while (choice)
{
    age = prompt("Enter your age : ")
    age = Number.parseInt(age)
    if (age <= 0)
    {
        console.error("Valid age not entered!")
    }
    else
    {
        alert(`Your age is : ${age}, and based on this, you can ${age > 18 ? 'surely drive' : 'cannot drive'}`)
    }
    choice = confirm("Do you want to see the prompt again? ")
}
let num = prompt("Enter a number : ")
num = Number.parseInt(num)
if (num <= 4)
{
    alert("Nothing happened")
}
else
{
    location.href = "https://google.com"
}
choice = prompt("Enter 1 for red, 2 for green and 3 for yellow : ")
choice = Number.parseInt(choice)
if (choice == 1)
{
    document.body.style.background = "red"
}
if (choice == 2)
{
    document.body.style.background = "green"
}
if (choice == 3)
{
    document.body.style.background = "yellow"
}