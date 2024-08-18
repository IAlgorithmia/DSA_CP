const a = [1, 5, 9, 0, -12]
let b = a.map((value, index, array) => {console.log(value**2, index, array)})
console.log(a)
//this is different from foreach since it creates a new array.
// the value index array thing can be done with foreach too
let c = a.filter((value) => {return value > 0})
console.log(c)
console.log(a)
let d = a.reduce((item1, item2) => {return item1 + item2})
console.log(d)
// reduce function reduces the array to a single value
// const reduce_func = (item1, item2) =>
// {
//     return item1 + item2
// }
// let d = a.reduce((item1, item2) => reduce_func(item1, item2))
// console.log(d)
// this gives the same result as the above code since we can make an arrow function, arrow functions just have shorter syntax in comparision with standard functions