let url = "https://kontests.net/api/v1/all"
let response = fetch(url)

response.then((value) => //value represnts the contests information coming from the API
{
    return value.json() //Ye normal syntax hai API recieve and send karne ka
}).then((value) =>
{
    ihtml = ""
    console.log(value)
    for (item in value) //We're recieving an array of objects, and objects se value fetching dot lagake hoti hai
    {
        console.log(value[item])
        ihtml += `<div class="card" style="width: 18rem;">
        <img src="..." class="card-img-top" alt="...">
        <div class="card-body">
            <h5 class="card-title">Contest Name : ${value[item].name}</h5> 
            <p class="card-text">Information about this contest : Start time : ${value[item].start_time} End time : ${value[item].end} Website : ${value[item].site} Joining Link : ${value[item].url} Starting Within Next 24 Hours : ${value[item].in_24_hours}</p>
            <a href="#" class="btn btn-primary">Go somewhere</a>
        </div>
    </div>`
    }
    card.innerHTML = ihtml
    return value
})

let card = document.getElementById("CardContainer")

let thenote = prompt("Enter the note : ")
localStorage.setItem("Note", thenote)

console.log(localStorage.getItem("Note"))