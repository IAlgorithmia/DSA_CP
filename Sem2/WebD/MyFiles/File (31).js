console.log("Hello world")
alert("Helloo world alert vala")
let k = prompt("Enter a value : ", "Jesus") //the second value is the optional default value
alert(`The value is ${k}`)
console.log("Hey there, baby")
console.log(console)
console.error("Hey this is an error!")
console.assert(5>56) //gives an error - Assertion failed
// console.assert(678>1) //doesnt give error but doesnt give output either
console.clear()
let obj = {a : 5, b : 6, r : 98}
console.table(obj)
console.warn("This is a warning")
console.info("This is some information")
alert("Enter your name!")
let name = prompt("Enter : ")
document.write(`Your name is ${name}`) //This writes in the document
let request = confirm("Do you want to write?") //returns 1 if ok is clicked and 0 if cancel is clicked
if (request)
{
    document.write("I am writing here now!")
}
else
{
    document.write("Please allow me to write! Please!")
}