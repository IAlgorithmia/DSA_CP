//Cookies are small string of data stored directly in the browser
//Whenever we write into the document.cookie, it never removes what was previously stored in it, it just appends the new value

console.log(document.cookie)//Syntax

document.cookie = "Jesus=MyLord"

document.cookie = "Radhe=OurLord"
document.cookie = "Jesus=OurLord" //This doesnt add a new cookie rather updates the previous one
//Cookies are typically stored as Key:Value pairs
let key = prompt("Enter the key : ")
let value = prompt("Enter the value : ")

document.cookie = `${encodeURIComponent(key)}=${encodeURIComponent(value)}` //encodeURIComponent() is used if we want to write special characters in the key values pairs too. decodeURIComponent() should also be used. Iske arguments mein 4kb se jyada data use nahi kar sakte

console.log(document.cookie)

document.cookie = "Hey=There ; path=/a ; expires = Tue, 29 March 2041 03:23:45 GMT" //These are called as cookie options, these are not different cookie but the options within the same cookie

//Around 20 cookies can be set on a particular domain