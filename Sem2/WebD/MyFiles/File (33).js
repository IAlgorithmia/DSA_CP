let choicesarr = ['Snake', 'Water', 'Gun'];
let choicesobj = {'Snake' : 0, 'Water' : 1, 'Gun' : 2};
let resultarr = [[0, 1 ,-1], [-1, 0, 1], [1, -1, 0]]
let choicecomp, choiceuser, mood, result;
do
{
    choicecomp = Math.floor(Math.random() * (Object.keys(choicesobj).length))
    choiceuser = choicesobj[prompt("Enter your choice - Snake, Water or Gun : ")]
    result = resultarr[choiceuser][choicecomp];
    switch (result)
    {
        case 0 :
        alert(`Your choice : ${choicesarr[choiceuser]} and  Computer's Choice : ${choicesarr[choicecomp]} Result :  It's a tie!`)
        break
        case 1 :
        alert(`Your choice : ${choicesarr[choiceuser]} and Computer's Choice : ${choicesarr[choicecomp]} Result : User has won!`)
        break
        case -1 :
        alert(`Your choice : ${choicesarr[choiceuser]} and Computer's Choice : ${choicesarr[choicecomp]} Result : Computer has won!`)
        break
    }
    mood = confirm("Do you want to play again? ")
} while (mood)