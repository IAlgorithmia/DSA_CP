let name1 = "Vaibhav";
let name2 = 'Sharma'
let i, j;
for (i = 0; i < name1.length; i++)
{
    console.log(name1[i])
    for (j = 0; j < name2.length; j++)
    {
        console.log(name2[j])
    }
}
let name3 = `This is a template literal written by : ${name1} ${name2}`
console.log(name3)
// these are called as template literals (inke andar hum ' adn " bhi bindass use kar sakte hain) and the process of interting variables into strings via template literals is called as string interpolation
// Escape sequnces : \', \n newline, \t tab, \r carriage return (takes the cursor to the beginning of the same line)