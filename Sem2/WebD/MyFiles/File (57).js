let p = fetch("https://api.open-meteo.com/v1/forecast?latitude=28.6519&longitude=77.2315&hourly=temperature_2m,relativehumidity_2m,dewpoint_2m,apparent_temperature,precipitation_probability,rain,cloudcover,windspeed_10m&current_weather=true")
// the apis return a promise
p.then((response) =>
{
    console.log(response.status) //usually 200
    console.log(response.ok) //should be true
    return response.json() // .json() ya .text() mein se hum at  time sirf ek run kar sakte hain
}).then((response) =>
{
    console.log(response)
})

// AJAX = Asynchronous Javscript and XML
//The default option of fetch is get action
// getting a response from an api is a two step process : an object of response class containing status and ok properties, then we access the body of the object in different formats
