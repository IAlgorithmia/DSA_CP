let addnow = document.getElementById("SubmitButton")
let removenow = document.getElementById("RemoveButton")
let deletenow = document.getElementById("DeleteButton")
let displaynow = document.getElementById("DisplayButton")

let target1 = document.getElementById("todo-input")
let target2 = document.getElementById("remove-input")

let writehere = document.getElementsByClassName("displayhere")[0]

let item

let i = 0

const myfunc1 = () =>
{
    i = i + 1
    item = target1.value
    key = "Item " + i
    localStorage.setItem(key, item)
    writehere.innerHTML = key + " Added"
}

const myfunc2 = () =>
{
    console.log("Clicking")
    item = target2.value
    writehere.innerHTML = "Item with value " + localStorage.getItem(item) + " has been removed"
    localStorage.removeItem(item)
}

const myfunc3 = () =>
{
    localStorage.clear()
    writehere.innerHTML = "The list has been cleared, " + i + " items have been deleted"
    i = 0
}

const myfunc4 = () =>
{
    ihtml = ""
    for (let a = 1; a <= i; a++)
    {
        ihtml += `Item ${a} ` + localStorage.getItem(`Item ${a}`) + "<br>"
    }
    writehere.innerHTML = ihtml
}

addnow.addEventListener("click", myfunc1)

removenow.addEventListener("click", myfunc2)

deletenow.addEventListener("click", myfunc3)

displaynow.addEventListener("click", myfunc4)