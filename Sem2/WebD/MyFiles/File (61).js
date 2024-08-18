//Session storage is same as localStogare, the difference is just that sessionStorage stays in the same tab, not another tab, and doesn't survive the page refresh. Even methods bhi same hain
//Storage event : 
//Whenever data gets updated in local or sessional storage, storage event triggers these properties
// Index, OldValue, NewValue, StorageArea (local or sessional), URL

window.onstorage = (e) =>
{
    alert("Storage kiya kya re tune")
    console.log(e)
}