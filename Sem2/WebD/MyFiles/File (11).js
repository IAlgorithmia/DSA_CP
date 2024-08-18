let myarray = ["Vaibhav", "John Wick", 34.77, 69, null, true, undefined]
for (let i = 0; i < (myarray.length); i++)
{
    console.log(myarray[i])
}
console.log(myarray.toString().length)
for (let i = 0; i <= myarray.toString().length; i++)
{
    console.log(myarray.toString()[i])
}
console.log(myarray.join("-_-")) //this joins the elements of the array using a seperator and returns a string
myarray.push("JEsus fkn christ") //This and pop() change the original string
// pop returns the popped value and push returns the new length of the array
console.log(myarray)
console.log(myarray.shift())//this removes the first element and returns it 
console.log(myarray.unshift(56)) //Adds the element passed into the array in the first position