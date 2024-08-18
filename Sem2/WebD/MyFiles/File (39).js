seconddiv.insertAdjacentHTML('beforebegin', '<div class = "test"> This is before begin <div>')
seconddiv.insertAdjacentHTML('beforeend', '<div class = "test"> This is before end <div>')
seconddiv.insertAdjacentHTML('afterbegin', '<div class = "test"> This is after begin <div>')
seconddiv.insertAdjacentHTML('afterend', '<div class = "test"> This is after end <div>')
seconddiv.remove() //This just removes the seconddiv ID element and the upper modifications also disappear
// Every name is self explanatory, just remember the syntax
// Now the main difference is that before begin <div> starting tag se pehle likha jayega, before end closing tag se just pehle likha jayega, afterbegin starting tag ke just andar, after end closing tag ke just outside elements dekhna inspect karke