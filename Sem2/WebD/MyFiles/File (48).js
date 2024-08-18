let promise1 = new Promise(function(resolve, reject)
{
    setTimeout(function(){
        console.log("We are done!")
        resolve(56)
    }, 2000)
})
promise1.then((value) =>
{
    console.log(value)
    let promise2 = new Promise(function(resolve, reject)
    {
        setTimeout(function(){
            console.log("YOyoyoyoyoyo")
            resolve("Oh yeah")
        }, 2000)
        
    })
    return promise2
}).then((value) => 
{
    console.log("Hippe Yippe " + value)
    return 2 //Although its not a promise value but we can still use its value by .then since its automacially turned into an automatically resolved promise
}).then((value) =>
{
    console.log("Pakka done re " + value)
})

const loadScript = (url) =>
{
    return new Promise( function(resolve, reject){
        let script_elem = document.createElement("script")
        script_elem.src = url
        document.body.appendChild(script_elem)
        script_elem.onload = () =>
        {
            resolve("The script has been loaded successfully")
        }
        script_elem.onerror = () =>
        {
            reject(0)
        }
    })
}
//We can add as many .thens as we like. This is called as promises chaining
let p1 = loadScript("https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js")
p1.then((value) => 
{
    console.log(value)
    return loadScript("https://cdn.jsdelibjhghjbvr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js")
}).then((value) => 
{
    console.log("Second SCript Ready")
}).catch((value) => //Catch is used for errors only
{
    console.log("We are sorry but we are having problems loading this script")
})
//If any .then fails then it'll directly go to .catch