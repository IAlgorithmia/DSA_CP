// Closure ka matlab a combination of a function with its behaviour in accordance with its lexical environment, bundled together

let message = "Good morning"

function myfunc() { //myfunc is a closure now, function inside function
    let message = "Good afternoon mate"

    let c = function () {
        console.log("Aur veere, " + message)
    } 

    message = "Are ye kya, value changed" //The final message will show this message variable becuase jab lexical environment return hota hai to name return hoga, uski value nahi. Value to agar hum bad mein change kar dein to that changed value will be returned
    return c
}

let a = myfunc()

a() //Although a function is returned which uses a value that's destroyed after the line 12 is reached, the functional behaviour is in accordance with its lexical environment