let entereddate, time, writeinme, year, month, date, hour, minute

let setwithtime = document.getElementById("SetWithTime")

let currentmonth, currentdate, currentyear, currenthour, currentminute
let intervalid

const runner1 = () => {
    intervalid = setInterval(func1, 1000)
}

const func1 = () => {
    entereddate = document.getElementById("date").value
    time = document.getElementById("time").value
    writeinme = document.getElementsByClassName("MujheUseKaro")[0]
    year = Number.parseInt(entereddate.slice(0, 4))
    month = Number.parseInt(entereddate.slice(5, 7))
    date = Number.parseInt(entereddate.slice(8, 10))
    hour = Number.parseInt(time.slice(0, 2))
    minute = Number.parseInt(time.slice(3, 5))
    a = new Date()
    currentyear = a.getFullYear()
    currentmonth = a.getMonth() + 1
    currentdate = a.getDate()
    currenthour = a.getHours()
    currentminute = a.getMinutes()
    if (currentyear == year && currentdate == date && currentmonth == month && currenthour == hour && currentminute == minute) {
        play()
        clearInterval(intervalid)
    }
}

function play() {
    var audio = new Audio('https://actions.google.com/sounds/v1/alarms/digital_watch_alarm_long.ogg');
    audio.play();
}

setwithtime.addEventListener("click", runner1)

// 2022-12-31 11:33