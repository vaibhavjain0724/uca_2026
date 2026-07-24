

// function updateUI(data , dataString){
//     for(const users of data.users){
//         dataString += users.firstName + ": Unknown<br>"
//     }
//     return dataString;
// }

// self.onmessage = function(event){
//     let dataString = "";
//     updateUI(event.data, dataString);
//     self.postMessage(dataString);
// }


self.onmessage = function(event) {
    const data = event.data;

    console.log("WORKER RECEIVED:", data);

    let dataString = "";

    for (const user of data.users) {
        dataString += `
    
                ${user.firstName} ${user.lastName} : Invalid
          
        `;
    }

    self.postMessage(dataString);
};