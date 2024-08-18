// de structuring is used to unpack values from an array or properties from an object into distinct variables
let arr = [1, 4, 4, 1, 3 ,5 ,9]

let [a, b, c, ...rest1] = arr //Extra values ho sakti hain but not less
let [x, , , y, ...rest2] = arr //The two 4s will be skipped

console.log(a, b, c, rest1)
console.log(x, y, rest2)

let obj = {"Value 1" : 1, "Value 2" : 2}
let {p, q} = obj
console.log(p, q)

//This is called as destructuring

let myarray = [1, 5, 12, 0, "HiBaby"]
let myobject = {...myarray}// This is called as Spread operator, Creates an object with keys 0, 1, 2 ,...
console.log(myobject) 

function sum(v1, v2, v3){
    return v1 + v2 + v3
}

console.log(sum(...myarray))

let anotherobject = {"Name" : "John", "Address" : 231, "Company" : "JasonMomoa"}

console.log({...anotherobject, "Name" : "KingOfTheSeas", "Company" : "TheHighTides"})  //What we didn't replace remains the same. If we write ...anotherobject in the end then the values aren't replaced   
//Local scope is of two types, block scope and function scope