function toggleChat(){
    let chatContainer = document.getElementById("chatContainer");
    if (chatContainer.style.display === "block"){
        chatContainer.style.display = "none";
    }
    else{
        chatContainer.style.display = "block";
    }
}

function addMessage(message, className){
    let chatBox = document.getElementById("chatBox");
    let messageDiv = document.createElement("div");
    messageDiv.classList.add(className);
    messageDiv.innerHTML = message;
    chatBox.appendChild(messageDiv);
}

function sendMessage(){
    let input = document.getElementById("userInput");
    let message = input.value.toLowerCase();
    if(message.trim() === ""){
        return;
    }
    addMessage("You: " + message, "user-message");
    let response = getBotResponse(message);
    addMessage("Bot: " + response, "bot-message");
    input.value="";
    let chatBox = document.getElementById("chatBox");
    chatBox.scrollTop = chatBox.scrollHeight;
}

function getBotResponse(message){
    if(message.includes("hello") || message.includes("hi") || message.includes("hey")){
        return "Hello! How can I help you today?";
    }
    else if(message.includes("admissions") || message.includes("admission") || message.includes("admit")){
        return "We are now accepting applications for the 2026 academic year. Please fill out the application form to apply.";
    }
    else if(message.includes("branch") || message.includes("branches") || message.includes("branch details")){
        return "We offer the following branches: Computer Engineering, Information Technology, Electronics and Telecommunication Engineering, Artificial Intelligence and Data Science, Electronics and Computer Engineering.";
    }
    else if(message.includes("contact") || message.includes("contact us") || message.includes("contact details")){
        return "Email: contact@pict.edu Phone: +91 9876543210";
    }
    else{
        return "I'm sorry, I can't help with that. Please try again.";
    }
}