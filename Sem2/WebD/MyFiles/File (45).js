//Async actions : We inititate now and they finish later like setTimeout. Iske karand code rukega nahi, but ye initite ho jayega and further code will be executed. It'll finish according to its details
//Sync actions initiate and finish one by one like prompt
//The DOM is a programming interface for web documents and represents the structure of an HTML page as a tree of objects.
let mydata = document.createElement("div") //Creates an element
mydata.innerHTML = "I am Vaibhav, my age is 19 and I am a student" //Data for element
let target = document.getElementById("firstdiv") //Place where the element will go  
target.appendChild(mydata) //Placed wrt to the target

function loadScript(url, callback1, callback2) //We are saying ke bhai script to add karo hi but sath sath lo ek function ko bhi call kr dena
{
    let elem = document.createElement("script")
    elem.src = url //element ki koi property hogi src, usko modify kara h
    document.body.appendChild(elem)
    elem.onload = function () //onload : Jab bhi script load ho jayega then this function will be called
    {
        console.log("Loaded script with src :"  + url)
        callback1(null, url)
        callback2(null, url)
    }
    elem.onerror = function () //If script couldnt be loaded successfully
    {
        console.log("Error loading script the url :"  + url)
        callback1(new Error("Src got some error"))
    }
}

const hello = (error, theurl) =>
{
    if (error)
    {
        console.log(error)
        sendEmergencyMessageToCeo()
        return
    }
    alert("Hello there. The link added is : " + theurl)
}

const gm = (error, theurl) =>
{
    if (error)
    {
        console.log(error)
        sendEmergencyMessageToCeo()
        return
    }
    alert("Good morning. The link added is : " + theurl)
}
loadScript("https://cdn.jsdelibjhghjbvr.net/npm/bootstrap@5.3.1/dist/js/bootstrap.bundle.min.js", hello, gm)

//When we have callbacks inside callbacks the code starts to grow horizontally and becomnes unreadable and difficult to manage. This is called as Pyramid of Doom or CallbackHell, its solution is promise. It is a promise of code execution, it helps in paraller processing