// Display initial alert message
// alert("Exams are near, have you started preparing for?");

// // Ask the user for input using prompt
// let response = prompt("Have you started preparing? (yes/no)", "");

// // Check the user's response and display appropriate confirm box
// if (response) {
//     response = response.toLowerCase();
    
//     if (response === "yes") {
//         confirm("Great! Keep up the hard work and good luck!");
//     } else if (response === "no") {
//         confirm("It's time to start! Don't leave it until the last minute.");
//     } else {
//         confirm("Please enter a valid response (yes or no).");
//     }
// } 

// else {
//     confirm("No response received. Stay focused and prepare well!");
// }


// SECOND

alert("Exams are near, have you started preparing for?");
let responce = prompt("HAve you Start Preparation(yes/no)", "");
if(responce)
{
    responce = responce.toLowerCase();

    if(responce === "yes")
    {
        confirm("Great!");
    }

    else if(responce === "no")
    {
        confirm("Then why are you waiting Start preparation");
    }

    else
    {
        confirm("give the yes or no only");
    }
    
}

else
{
    confirm("You dont say any think ok, Stay Focus on your study!!!!!!");
}