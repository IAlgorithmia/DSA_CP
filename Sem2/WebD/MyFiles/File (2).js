let a = null;
let b = 345;
let c = true;
let d = BigInt("5678") + BigInt("123");
let e = "Harry";
let f = Symbol("Vaibhav Rocks");
let g = undefined;
let h; //This also remains undefined
console.log(a, b, c, d, e, f, g, h);
console.log(typeof(a), typeof(b), typeof(c), typeof(d), typeof(e), typeof(f), typeof(g), typeof(h));
let item = 
{
    "Vaibhav" : true,
    5 : false,
    true : "Rakesh",
    0 : undefined,
    null : 12,
    13 : null
}
console.log(item["Vaibhav"], item[0], item[99])
//Not present key also returns undefined