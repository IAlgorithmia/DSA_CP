let num1 = [1, 2 ,3, "Vaibhav", "Jesus", "Hey", null, undefined]
console.log(num1.length)
delete num1[2] //changes original
console.log(num1.length)
//delete doesnt change the length, just makes the data at that position unavailable
let num2 = ["JesusisGod", "DaRok", 69.679, 0, null]
console.log(num1.concat(num2, num1))
//arguments as many as we want 
//doesnt change original
const compare = (a, b) =>
{
    return a - b
    //return b - a for descending order
}
let numbersarray = [1, 2, 5, -21, 0, 98, 99, 98.23]
console.log(numbersarray.sort())
console.log(numbersarray.sort(compare))
//sort sorts aplphabetically but performs as we want when we pass a function compare as shown above. It modifies original array
numbersarray.splice(2, 3, 1212, "Jesus is da only god", "inshallah wtf", null)
console.log(numbersarray)
// splice - position where we want to add, number of elements we want to delete starting from that position, elements to add. This returns the deleted elements
console.log(numbersarray.slice(2))
//Slice slices the given array. slice(2,6) means starting from index 2 upto index 5.
console.log(numbersarray.reverse())