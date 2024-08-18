const item = 
{
    "Rohan" : 2003,
    "Vibhu" : 12/2003
} 
console.log(item["Rohan"], item["Vibhu"]);
item["Rajesh"] = 22;
item["Vibhu"] = 999;
console.log(item);
//We can add items to the object later on too. item ek reference hai memory ke andar and I can change whats in that reference, but not the memory location the const variable is pointing to

let a = "Harry";
let b = 8;
a = b + a;
console.log(a, typeof(a));
//Strings and numbers can be added like concatenation