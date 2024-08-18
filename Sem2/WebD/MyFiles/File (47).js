let promise1 = new Promise(function(resolve, reject)
{
    console.log("Promise is pending")
    setTimeout(function(){
        console.log("I am promise and I am fulfilled")
        resolve(true) //If we dont call resolve or reject the state of promise remains unchanged instead of fulfilled or rejected and result of promise remains undefined instead of true or false  
        //We could've also written resolve(56) which would mean promise resolved with value 56
        console.log(promise1)
    }, 10000)
})

let promise2 = new Promise(function(resolve, reject)
{
    console.log("Promise is pending")
    setTimeout(function(){
        console.log("I am promise and I am rejected")
        reject(new Error("I am an error")) //resolve ke andar humesha value aati hai and reject ke andar hu,esha error aata hai
        console.log(promise2)
    }, 10000)
})

//The final result of the promise can be used by the user via catch and then
promise1.then((value) =>
{
    console.log("The value of promise 1 is " + value)
})

promise2.then((value) => //then only works then the promise is being fulfilled
{
    console.log("The value of promise 2 is " + value)
})

promise2.catch((error) => //This doesn't show the error in console 
{
    console.log("Some error occured in promise 2")
})
//Multiple promices are handled side by side and not one by one

promise2.then((value) =>
{
    console.log("The value of promise 2 is " + value)
}, (error) => //Writing an error part along with the value in .then function removes the need to use catch function
{
    console.log("Promise 2 has thrown an error : " + error)
})

console.log(promise1, promise2)