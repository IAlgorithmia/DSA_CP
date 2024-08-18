let p1 = new Promise(function (resolve, reject)
{
    setTimeout(function(){
        resolve("Value 1")

    }, 1000)
})
let p2 = new Promise(function (resolve, reject)
{
    setTimeout(function(){
        reject(new Error("Error"))

    }, 2000)
})
let p3 = new Promise(function (resolve, reject)
{
    setTimeout(function(){
        resolve("Value 3")

    }, 3000)
})

p1.then((value) =>
{
    console.log(value)
})

p2.then((value) =>
{
    console.log(value)
})

p3.then((value) =>
{
    console.log(value)
})

let promise_all = Promise.all([p1, p2, p3]) //When all three of these promises are resolved, the array of their values will be assigned to promise_all. If any one of the promises is rejected, then it returns an error. 
promise_all.then((value) =>
{
    console.log(value)
})

//for no error when one or more are rejected, use promise.allSettled

let promise_all = Promise.allSettled([p1, p2, p3]) //When all three of these promises are resolved, the array of their values will be assigned to promise_all. If any one of the promises is rejected, then it returns an error. 
promise_all.then((value) =>
{
    console.log(value)
})

//.race returns the promise which is completed first, BUT THIS GIVES AN ERROR IF PROMISE IS REJECTED. If we want otherwise, use promise.any
let promise_all = Promise.race([p1, p2, p3]) //When all three of these promises are resolved, the array of their values will be assigned to promise_all. If any one of the promises is rejected, then it returns an error. 
promise_all.then((value) =>
{
    console.log(value)
})

let promise_all = Promise.any([p1, p2, p3])
promise_all.then((value) =>
{
    console.log(value)
})

//promise.resolve(value) makes a fulfilled promise with the given value
//promise.reject(error) makes a rejected promise with the given value






