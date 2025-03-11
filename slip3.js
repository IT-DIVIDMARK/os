function validateForm(username, password) {
    // Username validation: Should be at least 5 characters and contain only letters and numbers
    let usernameRegex = /^[a-zA-Z0-9]{5,}$/;
    if (!usernameRegex.test(username)) {
        return "Invalid username. It must be at least 5 characters long and contain only letters and numbers.";
    }
    
    // Password validation: At least 8 characters, one uppercase, one lowercase, one number, and one special character
    let passwordRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;
    if (!passwordRegex.test(password)) {
        return "Invalid password. It must be at least 8 characters long and include an uppercase letter, a lowercase letter, a number, and a special character.";
    }
    
    return "Validation successful!";
}

// Example usage
let username = prompt("Enter your username:");
let password = prompt("Enter your password:");
alert(validateForm(username, password));


// function valid(uname, password)
// {
//     let unameRegex = /^[a-zA-Z0-9]{5,}$/;
//     if(!unameRegex.test(uname))
//     {
//         return "INVALID USERNAME";
//     }

//     let passwardRegex = /^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{8,}$/;
//     if(!passwardRegex.this(password))
//     {
//         return "INVALID PASSWORD";
//     }

//     return "Validation Successful!";
// }

// let uname = prompt("Enter Usaername : ");
// let password = prompt("Enter Password : ");
// alter(valid(uname, password));