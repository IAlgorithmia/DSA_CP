const createTodo = async (todo) => {
    let options = {
        method: "POST",
        headers: {
            "Content-type": "application/json"
        },
        body: JSON.stringify(todo),
    }
    let p = await fetch('https://jsonplaceholder.typicode.com/posts', options) //Syntax is : Link for API then options object
    let response = await p.json()
    //above dono ko await karna jaroori hai
    return response
}

const gettodo = async (id) => {
    let p = await fetch('https://jsonplaceholder.typicode.com/posts/' + id)
        let r = await p.json()
        return r

}

const mainfunc = async () => {
    let todo = { //stringify converts javascript object ot string, its opposite is JSON.parse
        title: "Vaibhav",
        body: "Bruh",
        userId: 1,
    }
    let result = await createTodo(todo)
    console.log(result)
    console.log(await gettodo(4))
}

mainfunc()