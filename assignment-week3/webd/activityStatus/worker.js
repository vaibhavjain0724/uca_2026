function printActiveStatus(data){
    for(const user of data.users){
        console.log(
            user.firstName + ": " + "Activity Status Invalid"
        )
    }
}

self.onmessage = function(event){
    printActiveStatus(event.data);

}