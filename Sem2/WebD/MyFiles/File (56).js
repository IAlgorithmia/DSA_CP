//Here we will see the use of promise.all

let promiser1 = async () => {
let p1 = new Promise(function (resolve, reject)
{
    setTimeout(function()
    {
        resolve(10)
    }, 1000)
})
return p1
}

let promiser2 = async () => {
let p2 = new Promise(function (resolve, reject)
{
    setTimeout(function()
    {
        resolve(20)
    }, 2000)
})
return p2
}

let promiser3 = async () => {
let p3 = new Promise(function (resolve, reject)
{
    setTimeout(function()
    {
        resolve(30)
    }, 3000)
})
return p3
}

const run = async () =>
{
    console.time("run")
    
    // let r1 = await promiser1() 
    // let r2 = await promiser2() 
    // let r3 = await promiser3() 
    //Ek ek karke karega wait to obvio 6 seconds hi lagenge in total

    let r1 = promiser1() 
    let r2 = promiser2() 
    let r3 = promiser3() 

    let allofthem = await Promise.all([r1, r2, r3]) //Promise.all helps in parallel processing

    //This only takes 3 seconds, thats the benefit

    console.log(r1, r2, r3)
    console.timeEnd("run")
}

run()