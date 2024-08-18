const myfunc = async () => {
    let MYP = new Promise(function (resolve, reject) {
        console.log("We're running the promise...")
        setTimeout(function () {
            reject(new Error("MYP promise has been rejected"))
        }, 3000)
    })
    return MYP
}

const caller = async () => {
    try {
        let promise_thing = await myfunc() //await keyword humesha only and only ek async function ke andar hi use hoga-
    }
    catch (error) {
        console.log(error)
    }
    finally {
        console.log("Bhai I'm a gym freak")
    }
}
caller()