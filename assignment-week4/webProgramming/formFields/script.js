const fields = [ 
  "First Name", 
  "Last Name", 
  "Email"
]; 

function generateTable(array){
    const div = document.getElementById("data");
    const data =
    
    
    array.map(field => 
        
        `<label>${field}</label>
         <input type="text">`

    ).join("")
   

    div.innerHTML = data;
}
generateTable(fields)