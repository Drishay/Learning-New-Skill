let userScore = 0;
let compScore = 0;

const choices = document.querySelectorAll(".choice");         
const msg = document.querySelector("#msg");
const userScorePara = document.querySelector("#user-score");
const compScorePara = document.querySelector("#comp-score");

const genComputerChoice = () =>{
    const options =["rock", "paper", "scissors"]; //rock, paper, scissors choices for the comp
    /* Math.random() generates a random number from 0 to 1, and by multiplying it with a number say 3, it generates
    a random number between 0 and 3, but since it could be decimal number too, thus we have to use Math.floor() to 
    convert into integer values
    */
    const random = Math.floor(Math.random() * options.length); //generate random number from 0 to 3, i.e 0,1,2
    return options[random]; //return the choice from the array at the random index
}

const drawGame   = () =>{
    // console.log("draw");
    msg.innerText = "Game draw!";
    msg.style.backgroundColor = "gray";
};

const showWinner =(userWin, userChoice, compChoice) =>{
    if(userWin){
        // console.log("USER WIN");
        msg.innerText = `You Win! ${userChoice} beats ${compChoice}`;
        msg.style.backgroundColor = "green";

        userScore++;
        userScorePara.innerText = userScore;
    }
    else{
        // console.log("User loss");
        msg.innerText = `You lost! ${compChoice} beats ${userChoice}`;
        msg.style.backgroundColor = "red";
        compScore++;
        compScorePara.innerText = compScore;
    }
};

const playGame = (userChoice)=>{
    // console.log("User choice = ", userChoice);
    //generate computer choicE
    const compChoice = genComputerChoice();
    // console.log("Comp choice = ", compChoice); //comp choice

    if(userChoice === compChoice){
        // draw game
        drawGame();
    }
    else{
        let userWin = true;
        if(userChoice === "rock"){
            //compChoice === "paper" or "scissor"
            userWin = compChoice === "paper" ? false : true;
        }
        else if (userChoice === "paper"){
            //compChoice === "stone" or "scissor"
            userWin = compChoice === "scissors" ? false : true;
        }
        else if (userChoice === "scissors"){
            // compChoice === "stone" or "paper"
            userWin = compChoice === "rock" ? false : true;
        }
        showWinner(userWin, userChoice, compChoice);
    }

};

choices.forEach((choice) => {
    // console.log(choice);
    choice.addEventListener("click", () => {
        
        const userChoice = choice.getAttribute("id"); //by this, we get the id of the choice.
        // console.log("choice was clicked" , userChoice);
        playGame(userChoice);

    });

 });