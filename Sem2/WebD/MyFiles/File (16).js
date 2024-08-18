let num = 1 + Math.floor(Math.random() * 99)
//Math.random gives a number between 0 (inclusive) and 1(exclusive)
console.log(num)
let score = 100
let attempts = 0
let guess = prompt("Guess the number : between 1 and 100, both inclusive")
guess = Number.parseInt(guess)
attempts++
while (guess != num)
{
    let guess = prompt("Guess the number : between 1 and 100, both inclusive")
    guess = Number.parseInt(guess)
    attempts++
}
console.log(`Congratulations on guessing the number! Your score is ${score - attempts + 1}`)