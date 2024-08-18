    //STRINGS ARE IMMUTABLE, EACH METHOD.FUNCTION RETURNS A NEW STRING AND DOESNT CHANGE THE EOLDER STRING

    let name1 = "Harry\""
    console.log(name1.length) //it is property, prints 6 since \" is  a single character
    console.log(name1.toUpperCase()) //this and below are methods/functions
    console.log(name1.toLowerCase())
    console.log(name1.slice(2,5))
    //slice mein agar second argument na de to from th given ndex to the last index jata hai string
    console.log(name1.replace("rry", "rish"))
    let name2 = "Verma"
    console.log(name1.concat(" is a good boy like ", name2))
    // concat ismein jitne marzi hum add kar sakte hain, as much as we like
    let name3 = "   H a r is h           "
    console.log(name3.trim())

    let name4 = "Bachna hai haseeeno, lo mai aa gaya"
    let word = "haseeeno"
    console.log(`The word ${word} is ${name4.includes(word) ? 'present' : 'not present'} in the string`)
    console.log(name4.startsWith("Bachna h"))
    console.log(name4.endsWith("a gaya"))
    console.log(name4.toLowerCase())
    let name5 = "please give Rs 1000"
    console.log(name5.slice("please give Rs".length))

    //Trying to change the character at a position in a string deson't give an error but the string doesn't change