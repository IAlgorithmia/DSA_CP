// function() is equivalent to () =>

const myobject = {
    Name : "Shashwat Sir",
    Role : "Web Developer",
    Experience : "30 Years",
    show : function() { //Arrow nahi use kar sakte here else this. wont work
        setTimeout(() => { //Use only arrow function here

            console.log(`The name is ${this.Name} and the role is ${this.Role} with an experience of ${this.Experience}`) //this. lagake use kar sakte hain the keys of an object inside a function defined in the same object. Set timeout ke andar this wont work
        }, 3000)
    }
}

console.log(myobject.Name, myobject.Role, myobject.Experience)
myobject.show()

// If we use this.alone, it refers to the gobal object, if inside an object, then this will refer to the same object, if we use this for an event like setTimeout then this will refer to the element that recieves the event