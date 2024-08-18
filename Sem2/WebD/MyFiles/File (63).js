// IIFE - Immediately invoked functional expressions
let a = () =>
{
    return new Promise(function(resolve, reject){
        setTimeout(function(){
            resolve(456)
        }, 2000)
    })
}

(async () =>
{
    let b = await a()
    console.log(b)
    let c = await a()
    console.log(c)
    let d = await a()
    console.log(d)
})()

//This method of writing is IIFE