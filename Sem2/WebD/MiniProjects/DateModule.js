let writehere = document.getElementById("seconddiv");
let month = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"];
let dayNames = ["Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"];
let a, day, date, monthName, hour, minute, second

const writer = () => {
a = new Date();
day = dayNames[a.getDay()];
date = a.getDate();
monthName = month[a.getMonth()];
hour = a.getHours();
minute = a.getMinutes();
second = a.getSeconds();
writehere.innerHTML = `Today, it's ${day}, ${date}th ${monthName} and the time is ${hour}:${minute}:${second}`;
};

writer()

// Update the content every second
setInterval(writer, 1000); 
