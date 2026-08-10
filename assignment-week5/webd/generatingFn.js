function* calculator(initial) {
    let result = initial;

    while (true) {

        let input = yield result;

        if (
            !input ||
            !["add", "subtract", "multiply", "divide"].includes(input.operation) ||
            typeof input.value !== "number"
        ) {
            console.log("Invalid input");
            continue;
        }

        switch (input.operation) {

            case "add":
                result += input.value;
                break;

            case "subtract":
                result -= input.value;
                break;

            case "multiply":
                result *= input.value;
                break;

            case "divide":
                if (input.value === 0) {
                    console.log("Cannot divide by zero");
                    continue;
                }

                result /= input.value;
                break;
        }
    }
}