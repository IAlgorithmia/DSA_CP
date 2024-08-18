//Cookies har request ke sath semd hoti hain but local storage nahi. This data stays even after a refresh and even after a browser restart

localStorage.setItem("name", "Vaibhav")

let key = prompt("Enter the key you want to set : ")
let value = prompt("Enter the value you want to set : ")

localStorage.setItem(key, value)

console.log(localStorage.getItem(key)) //show the value

console.log(`The value at the key ${key} is ${value}`)

setTimeout(function(){
    if (key == "red" || key == "blue")
    {
        localStorage.removeItem(key)
    }
}, 5000)

console.log(localStorage.length)  //Property hai, tells the length of the localStorage

console.log(localStorage.key(0)) //Index ke hisab se key return kar deta hai    

// Key and value both should be strings in localStorage

//JSON.stringify(object) objects to json strings
//JSON.parse(string)    strings to objects

localStorage.clear() //Sab khatam kar deta hai