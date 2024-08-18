first.className = "red dark-text"
// This changes the class of the element with ID first
console.log(first.classList) //Displays the list of all the classes a particular element has
first.classList.remove("red") //To remove a class
first.classList.add("yellow") //To add a class
first.classList.toggle("red") //Agar hai to hata dega, nahi hai to laga dega
first.classList.contains("yellow") //Returns true or false based on whether that class is present or not