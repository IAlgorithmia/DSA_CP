//Hum kisi bhi function ko async bana sakte hain and uske andar promise ko await kar sakte hain
async function harry()
{
    let delhiweather = new Promise(function(resolve, reject){
        setTimeout(function(){
            resolve("21 deg")
        }, 5000)
    })
    let bangloreweather = new Promise(function(resolve, reject){
        setTimeout(function(){
            resolve("27 deg")
        }, 10000)
    })
    // delhiweather.then(alert) //Promise resolve hone par value ko alert kardo
    // bangloreweather.then(alert)
    console.log("Fetching Delhi Weather Please Wait...")
    let delhiW = await delhiweather //await stops the flow of execution 
    console.log("Delhi Weather Has Been Fetched : " + delhiW)
    console.log("Fetching Banglore Weather Please Wait...")
    let bangloreW = await bangloreweather //await stops the flow of execution 
    console.log("Banglore Weather Has Been Fetched : " + bangloreW)
    return [bangloreW, delhiW]
}
console.log("Welcome to the Weather Department")
let a = harry()
a.then((value) =>
{
    console.log(value)
})
//async makes the returned value of the function as a promise
