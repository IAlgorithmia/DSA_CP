let num = [3, 54, 9, -1, 0, 22,98]
for (let i = 0; i < num.length; i++)
{
    console.log(num[i])
}
num.forEach((element, index, array) => console.log(element * element))
//this is a for-each loop, it has supports arguments, element (in the object), index, array
let myname = "Vaibhav"
let namearray = Array.from(myname)
//converts to array
console.log(namearray)
for (let i of num)
{
    console.log(i)
}
//Gives the values
for (let i in num)
{
    console.log(i)
}
//socha jaaye to everything is object, hence arrays mein bhi key value pairs hongi, hence since for in returns the keys, it's returning the index values of the array :)