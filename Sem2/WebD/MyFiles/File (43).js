//Add event listener is used to assign multiple handlers to an event

// let x = function(e)
// {
    // alert("Hello world1")
// }

//This e is event pointer, passed automatically to the function. Whenever an event happens, browser creates an event object, put details into it and passes it automatically as an argument to the handler 

let y = function(e)
{
    console.log("Hello world2")
    console.log(e)
    console.log(e.target)
    console.log(e.type)
    console.log(e.currentTarget)
    console.log(e.clientX, e.clientY)
}

// firstdiv.addEventListener('click', x
// )
firstdiv.addEventListener('click', y
)

//In each of these, we fitst write the event then the handler of that event

let a = prompt("Enter your favourite number : ")
a = Number.parseInt(a)

// if (a == 2)
// {
    // firstdiv.removeEventListener('click', x)
// }
if (a == 1)
{
    firstdiv.removeEventListener('click', y) //idhar y ki jaga if we declare the same function again then it won't work since they'll be different declarations of the functions
}