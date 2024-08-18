// Regular Expressions 

let regex1= /very/g //g means global
let regex2 = /.orny/g //Matlab orny dhoondo and uske ek left ka ek character kuch bhi ho sakta hai
let regex3 = /.[ao]rny/g //Matlab same as above just arny and orny dono dhoondo chalega
let regex4 = /.[a-o]rny/g //Same as above just ab sirf a and o i jaga ab koi bhi letter a se o ke beech mein
let regex5 = /.[^a-o]rny/g //a se o ke beech mein first character nahi hona chahiye
let regex6 = /^abc\./g //A line that starts with abc, \. means abc ke baad . aana chahiye, because sirf dot lagate that wouldve meant any character after abc
let text = "Vaibhav is a very very very horny boy very very corny lorny torny"

console.log(text.replace("very", "VERY")) //Replaces only the first occurence
console.log(text.replace(regex1, "VERY")) //Replaces every occurence
console.log(text.replace(regex2, "LMAO"))