document.write("Hello there")

alert("Aur bhi londe kya haal hai")

// let a = setInterval(
//     function () {
//         alert("Aur ab kya haal hai?")
//     }, 7000
// )

//The above runs once again after 7s

//In above, a is a timer ID, then a function, then a time interval, then two arguments can be given like below

// const sum = (a, b, c) => {
//     console.log("Yes I'm running hahaha " + a + b + c)
// }

// setTimeout(sum, 2000, 5, 3, 4)

//setTimeout runs once again, but setInterval keeps running again and again, clearTimeout stops setTimeout and clearInterval clears setInterval

let m = setInterval(
    function (a, b ,c) {
        alert("The sum of the three numbers is " + a + b + c)
    }, 5000, 1, 64, 2
)

let choice = prompt("Do you want to tell your mood again and again? (1 for yes, 0 for no)")

if (Number.parseInt(choice) == 0)
{
    clearInterval(m);
}