function adder(a, b)
{
    console.log("Addition has been performed!");
    let ans = a + b;
    a++;
    b++;
    //This doesn't change the original values of the parameters
    console.log(a, b);
    return (ans);
}
let a = 5;
let b = 8;
let c = adder(a, b);
console.log(c);
console.log(a, b);

const sum = (a, b) =>
{
    console.log("The arrow function has been called and it's returning the sum : ", a + b);
}
//This is another way of declaring a function, arrow function method, here its a const type function
sum(9, 0);

let items = 
{
    "Rice" : 1, 
    "Banana" : 4, 
    "Apple" : 2, 
    "Mango" : 5
}

// Object.keys(items) returns an array of all the keys
console.log(Object.keys(items));

for (let i = 0; i < Object.keys(items).length; i++)
{
    console.log("The quantity of " + Object.keys(items)[i] + " is " + items[Object.keys(items)[i]]);
}
// .length returns the length, the second term returns the item name, the last term mei item name ko object ke andar dal dia to access the key
for (let key in items)
{
    console.log(key);
    console.log("The quantity of " + key + " is " + items[key]);
}

for (let a of "Rohan")
{
    console.log(a);
}
//See the difference!
for (let a in "Rohan")
{
    console.log(a);
}

let correctnumber = prompt("Enter the number of your choice : ");
let num;
do
{
    num = prompt("Enter the number entered previously by you : ")
} while (num != correctnumber)