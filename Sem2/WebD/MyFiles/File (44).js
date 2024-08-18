document.getElementById("button 1").onclick = () =>
{
    alert("Oh yeah you like to be punished don't you!")
}
document.getElementById("button 2").onclick = () =>
{
    alert("You have to do something dirty to impress me!")
}

const google = () =>
{
    let url = "https://www.google.com"
    let win = window.open(url) //opens the  url in a new tab
    win.focus() //shifts the fivcus on that tab
}

const twitter = () =>
{
  let url = "https://www.twitter.com";
  let win = window.open(url); //opens the  url in a new tab
  win.focus(); //shifts the fivcus on that tab
}

document.getElementById("button 3").addEventListener("click", google)

document.getElementById("button 4").addEventListener("click", twitter)

setInterval(async function()
{
    let url = 'https://jsonplaceholder.typicode.com/todos/1'
    document.write(await fetchContent(url))
}, 5000)