const users = [

    {name:"Alice", age:53},
    {name:"Tim", age:74}

]


function generateTable(array){
    const div = document.getElementById("data");
    const data =
    
    `<table>
    ${array.map(user => 
        
        `<tr>
            <td>${user.name}</td>
            <td>${user.age}</td>
        </tr>
        `

    ).join("")}
    </table>
    `;

    div.innerHTML = data;
}
generateTable(users)