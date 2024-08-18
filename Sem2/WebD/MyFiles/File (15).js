arraynum = [1 ,4, 32, 98, -21.45, 3,14159, 0]
let n = prompt("Enter the number (Press 0 to stop) : ");
n = Number.parseInt(n)
//Prompt ke baad agar as a number use karna hai to dont forget to use Number.parseInt()
while (n != 0)
{
    arraynum.push(n)
    n = prompt("Enter the number (Press 0 to stop) : ")
    n = Number.parseInt(n)
}
console.log(arraynum)
let a = arraynum.filter((value) => {return (value % 10) == 0})
console.log(a)
let b = arraynum.map((value) => {return value**2})
console.log(b)
n = prompt("Enter the number whose factorial you want to find : ");
n = Number.parseInt(n)
let factarr = []
for (let i = n; i >= 1; i--)
{
    factarr.push(i)
}
let factorial = factarr.reduce((item1, item2) => {return item1 * item2})
console.log(`The factorial of ${n} is ${factorial}`)