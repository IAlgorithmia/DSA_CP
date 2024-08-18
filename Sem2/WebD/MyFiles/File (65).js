// Hoisting refers to the process whereby the interpreter appears to move the declarations to the top of the code before execution
// But this happenes only with declarations not with initializations

thefunc()
console.log(a) 

//Undefined will be printed because declaration is hoisted but not initialization

function thefunc() {
    console.log("This function is being called now")
}
var a = 9 

//Agar iski jaga let ya const use karte then error aata upar vaale mein
// Note that function expression and class expressions are not hoisted
// this will appear as :
// function thefunc()
// {
//     console.log("This function is being called now")
// }
// thefunc()
// JAN HIT MEIN JAARI - DECLARE ALL THE VARIABLES AT THE TOP