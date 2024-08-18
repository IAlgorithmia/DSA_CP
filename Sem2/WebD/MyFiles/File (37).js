let id1 = document.getElementById("id1")
let sp1 = document.getElementById("sp1")
console.log(id1)
console.log(id1.matches("#id1")) //Sees whether a css selector matches it or not
console.log(id1.matches(".box"))
console.log(sp1.closest("#sp1")) //Looks for the closest ancestor of the element with the given selector, including the element itself
console.log(id1.contains(sp1)) //Returns boolean based on whether sp1 is contained in id1 or not, also if tboth the elements are the same. Also in above methods, we pass selector but here we pass the element itself
console.log(id1.contains(id1))
console.log(sp1.contains(id1))
console.log(document.getElementsByTagName("li")[0])
document.getElementsByTagName("li")[0].style.color = "red"
//Making a table without tbody results in sourcepage showing no tbody and inspect element showing tbody because browser automatically adds a tbody element
let parent = document.getElementsByClassName("parent")[0]
parent.firstElementChild.style.color = "green"
parent.lastElementChild.style.color = "green"
let thelist = document.getElementsByTagName("li")
for (let i = 0; i < thelist.length; i++)
{
    thelist[i].style.background = "cyan"
}