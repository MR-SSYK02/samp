$(document).ready(function(){
    $('#login').click(function(){
        window.location.href = 'login.html';
    });
});
$(document).ready(function(){
    $('#loginform').submit(function (e) { 
        e.preventDefault();
        window.location.href='index.html';
        
    });
});
// $(document).ready(function () {
//     $("#loginForm").submit(function (event) {
//         event.preventDefault(); // Prevent the form from submitting normally

//         // Get input values
//         const username = $("#username").val();
//         const password = $("#password").val();

//         // Simple validation (you can add more complex checks)
//         if (username === "admin" && password === "password") {
//             // Redirect to the main page if login is successful
//             window.location.href = "index.html";
//         } else {
//             // Show error message if login fails
//             $("#error").text("Invalid username or password. Please try again.");
//         }
//     });
// });