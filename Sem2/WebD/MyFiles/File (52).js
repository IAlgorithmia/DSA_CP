setTimeout(function(){
    console.log("Hacking username and password...")
}, 3000)

setTimeout(function(){
    console.log("Username and password retrieved!")
}, 5000)

//Agar koi error setTimeout ke andar aata hai then it wont stop the flow of execution since statements saari execute ho jati hain bu agar bahar aata hai then it'll stop

try{ 
    //Iske andar sirf synchronoous code handle kiya jayega, scheduled code like setTimeout ke andar daldi agar below statement to error aa jayega, because the engine has already left the try catch construct
    console.log(bhai_kya_kar_raha_hai_tu) //This statement alone would've given an error
}
catch(error)
{
    console.log(error) //Ye statement jaroori nahi hai
    console.log("Balle balle error pencho ma chudaye")
}