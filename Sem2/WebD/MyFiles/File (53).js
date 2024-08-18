//every error has two main parts, name and message
try
{
    let age = prompt("Enter your age : ")
    age = Number.parseInt(age)
    if (age > 150)
    {
        throw new Error("Bhai kya kar raha hai tu") //SyntaxError, ReferenceError, ... etc can also be written
    } 
    else
    {
        console.log("The age is : " + age)
    }
}
catch (error){
    console.log(error.name)
    console.log(error.message)
}
finally //finally is written so that even if catch part has an error in itself, finally clause will run
{
    console.log("This is a statement thats always executed")
}

//Even if this ia all defined inside a function and there's a return inside the try block, the finally clause will still run just before the engine exits the function