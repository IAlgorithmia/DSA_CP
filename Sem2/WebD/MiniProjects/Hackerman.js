//Hackerman not complete

let writeinme = document.getElementById("writehere")

let lines = ["Initializing Hack tool", "Hacking has been initiated", "500 passwords tried and match has been found", "Facebook, Gmail and Instagram IDs have ben cracked", "Hacking complete, passwords are saved as txt file", "Closing the Program", ""]

const sleep = (seconds) => {
    let p = new Promise(function (resolve, reject) {
        setTimeout(function () {
            resolve(true)
        }, seconds * 1000)
    })
    return p
}

const writer = async () => {
    for (let i = 0; i < lines.length; i++) {
        let k = await sleep(2)
        writeinme.innerHTML = lines[i]
    }
    document.body.innerHTML = " "
    document.body.style.backgroundImage = "none"; 
}

writer()