const computerChoiceDisplay = document.getElementById('computer-choice')
const userChoiceDisplay = document.getElementById('user-choice')
const resultDisplay = document.getElementById('result')
const possibleChoices = document.querySelectorAll('button')
let userChoice
let computerChoice

possibleChoices.forEach(possibleChoice => possibleChoice.addEventListener('click', (e) => {
    userChoice = e.target.id
    userChoiceDisplay.innerHTML = userChoice
    generateComputerChoice()
    getResult()
}))

function generateComputerChoice() {
    const randomNumber = Math.floor(Math.random() * possibleChoices.length) + 1
    
    if (randomNumber === 1){
        computerChoice = 'rock'
    }

    if (randomNumber === 2){
        computerChoice = 'paper'
    }

    if (randomNumber === 3){
        computerChoice = 'scissors'
    }

    computerChoiceDisplay.innerHTML = computerChoice
}

function getResult() {
    if (computerChoice === userChoice){
        resultDisplay.innerHTML = "it's a draw!"
    }
    else if (computerChoice === "rock" && userChoice === "paper"){
        resultDisplay.innerHTML = "you win!"
    }
    else if (computerChoice === "paper" && userChoice === "scissors"){
        resultDisplay.innerHTML = "you win!"
    }
    else if (computerChoice === "scissors" && userChoice === "rock"){
        resultDisplay.innerHTML = "you win!"
    }
    else
    {
        resultDisplay.innerHTML = "you lose!"
    }
}