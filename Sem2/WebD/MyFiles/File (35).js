const changetocolor = (colorname) =>
{
    document.body.firstElementChild.firstElementChild.style.color = colorname;
}
b = document.body
console.log(b.firstElementChild) //only element 
console.log(b.firstChild) //child node to koi bhi ho sakta hai
c = document.getElementsByClassName("container")[0]
console.log(c.previousElementSibling)
// similarly nextElementSibling, firstElementChild, lastElementChild
changetocolor("red")