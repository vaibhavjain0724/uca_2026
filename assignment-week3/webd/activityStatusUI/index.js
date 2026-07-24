// async function getData(link){
//     const response =await fetch(link);
//     const data =await response.json();
//     return data;
// }

// function updataUI(data){
//     worker1.postMessage(data);

//     worker1.onmessage = function(event){

//         const dataString = event.data;

//         document.getElementById("users").innerHTML = dataString;

//     }
// }


// worker1 = new Worker("./worker.js");

// getData("https://dummyjson.com/users").then(updataUI);


//with logs
async function getData(link) {
    const response = await fetch(link);
    const data = await response.json();

    console.log("FETCHED:", data);

    return data;
}

function updataUI(data) {
    console.log("SENDING TO WORKER:", data);

    worker1.postMessage(data);

    worker1.onmessage = function(event) {
        console.log("GOT FROM WORKER:", event.data);

        document.getElementById("users").innerText = event.data;
    };
}

const worker1 = new Worker("./worker.js");

getData("https://dummyjson.com/users").then(updataUI);