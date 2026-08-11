function* fibo(){

    let a = 0;
    let b = 1;

    while(true){

        let result = yield a;

        let next = a + b;
        a =b;
        b = next;


    }

}

const fib = fibo(); 
console.log(fib.next());
console.log(fib.next());
console.log(fib.next());
console.log(fib.next());
console.log(fib.next());
console.log(fib.next());