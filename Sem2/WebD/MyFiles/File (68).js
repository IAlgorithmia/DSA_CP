const thefunc = () =>{
    return new Promise(function(resolve, reject)
    {
        setTimeout(function(){
            resolve(true)
        }, 2000)
    })
}

(async () => {
    let waitfortwo = await thefunc()
    console.log("Hello")
    let waitforanothertwo = await thefunc()
    console.log("World")
})()

let myarray = [1 ,4, 12]

const findavg = (a, b, c) =>{
    return (a + b + c)/3
}

console.log(`The average is : ${findavg(...myarray)}`) //This is spread syntax