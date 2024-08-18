console.log(document.getElementsByTagName("span")[0]) //presents the element as an element of DOM tree
console.dir(document.getElementsByTagName("span")[0]) //presents the element as an object and shows all its properties
console.log(document.body.firstChild.nodeName) //returns empty text name
console.log(document.body.firstElementChild.nodeName) //returns span name
document.firts
let d = document.getElementById("Im")
console.log(d.innerHTML)
d.innerHTML = "<i>Hey I am an ialic tag</i>" //Doesnt replace the targeted element, uske andar dal deta hai
//innerHTML is valid only for Tagelements 
console.log(d.outerHTML)
d.outerHTML = "<div>Hey I am an extra weird tag</div>" //Completely replaces the elements and its contents
let a = document.body.firstChild.data //Both of these are same
let b = document.body.firstChild.nodeValue //Both of these are same
console.log(a, b)
console.log(document.body.textContent)
let c = document.getElementById("tobehidden")
c.hidden = true