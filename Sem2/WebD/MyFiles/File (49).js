let p1 = new Promise(function(resolve, reject)
{
    console.log("The promise is not resolved yet")
    setTimeout(function(){
        console.log("Congratulations the promise has been resolved");
        resolve(1)
    }, 5000)
})

p1.then((value) =>
{
    return new Promise(function(resolve, reject)
    {
        setTimeout(function()
        {
            console.log("The second promise is now resolved")
            resolve(4)
        }, 5000)
    })
}).then((value) => 
{
    console.log("The returned value of the above promise is " + value)
})

p1.then((value) =>
{
    console.log("Yippe Ka Ye Lappy")
})

//In this way multiple handlers can be attached to the same Promise, this is not promise chaining, the above one is. These .thens are run independently