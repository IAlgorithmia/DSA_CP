let promise = new Promise(function(resolve, reject)
{
    alert("Hello")
    resolve(56)
})

console.log("Hello one")

setTimeout(function ()
{
    console.log("Hello in 2 seconds")
}, 2000)

console.log("My name is " + "Hello three")

//Promise object has two properties : State and result
//State is initially pending then changes to fulfilled when resolve is called or rejected when reject is called
//Result is initially undefined then changes value to resolved or rejected
//State and result values hoti hain associated with the promise but they can't be accessed