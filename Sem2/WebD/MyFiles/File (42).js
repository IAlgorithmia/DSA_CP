//Whenever someething happens in our website like a mouse goes somewhere, that generates and eventand those are called as browser events
let a = document.getElementsByClassName("container")[0]
a.onclick = () => 
{
    a.innerHTML("Hellow there, General Kenobi")
}

//Click karna ek event hai, onclick vagerah event handlers hain, Javascript mein agar event handler likha hai to HTML vale handlers override ho jayenge
