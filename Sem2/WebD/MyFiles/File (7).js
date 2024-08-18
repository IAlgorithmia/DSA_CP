// for in loop = iterates through the keys of an object, used for objects
// for of loop = iterates through the values of an object, used for iterable items, objects are not iterable items. Ye mat samajhna ke ye keys ki values dedega
n = prompt("Enter the number of natural numbers whose sum you want : ");
sum = 0;
n = Number.parseInt(n);
for (let i = 1; i <= n; i++)
{
    sum += i;
}
console.log("The sum of the first " + n + " natural numbers is " + sum);
// console.log(i) This statement gives an error because scope of let is local. If var were used, the last value would've been printed
// in js concatenation of string and numbers can be done

let marks =
{
    "Rohan" : 90,
    "Vaibhav" : 88,
    "Ramesh" : 70,
    "Jason" : 59,
    "Mark" : 98,
}

for (let a in marks)
{
    console.log("The marks of " + a + " are " + marks[a]);
}

for (let a of "Harry")
{
    console.log("The letter is " + a);
}

let m = prompt("Enter any number : ");
let j = 1;
while (j <= m)
{
    console.log(j)
    j++;
}

j = 1;
do
{
    console.log(j)
    j++;
    
} while (j <= m)





