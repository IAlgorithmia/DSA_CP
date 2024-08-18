const loader = async (url) =>
{
    let p1 = new Promise(function(resolve, reject)
    {
        console.log("Loading the JS file into the HTML page...")
        setTimeout(function()
        {
            let elem = document.createElement("script")
            elem.src = url
            document.body.appendChild(elem)
            elem.onload = () => { //Script adding process mein onload humesha use karna for verification
                resolve("Successfully Added")
            }
        }, 3000)
    })

    p1.then((value) =>
    {
        console.log("The JS file at : " + url + " has been loaded successfully, with promise value : " + value)
    })
    return p1 //Jab promise return ho raha hoga along with async await then isiki return value ke liye wait kiya jayega
}

const myfunc = async () =>
{
    console.log(new Date().getMilliseconds)
    let a = await loader("https://cdn.jsdelivr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js")
    console.log(new Date().getMilliseconds)
    console.log(a)
    a.then((value) =>
    {
        console.log("The final value of the declared variable is : " + value)
    })
}

myfunc()