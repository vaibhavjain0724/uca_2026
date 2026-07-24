async function fetchData(link){
    const response = await fetch(link);

    if(!response.ok){
        console.log("failed to fetch");
        return;
    }

    const data = await response.json();
    worker.postMessage(data);
}

const worker = new Worker("./worker.js");

fetchData("https://dummyjson.com/users")