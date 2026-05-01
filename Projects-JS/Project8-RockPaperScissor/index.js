let buttons = document.querySelectorAll(".button");
let pscore = document.getElementById("pscore");
let cscore = document.getElementById("cscore");
let player = document.getElementById("player");
let computer = document.getElementById("computer");
let result = document.getElementById("result");


function computerPlay(){
    let compPlay = Math.floor(Math.random()*3);
    return compPlay;
}
function evalComputer(compPlay){
    let computer;
    switch (compPlay){
        case 0:
            computer = 'rock';
            break;
        case 1:
            computer = 'paper';
            break;
        case 2:
            computer = 'scissor';
            break;
    }
    return computer;
}
function evalAnswer(id){
    let playerPlay;
    id = String(id).toLowerCase();
    switch (id){
        case 'rock':
            playerPlay = 0;
            break;
        case 'paper':
            playerPlay = 1;
            break;
        case 'scissor':
            playerPlay = 2;
            break;
    }
    return playerPlay;
}

buttons.forEach(button => {
    button.addEventListener("click", event =>{

        let id = button.id;
        id = id.toString().charAt(0).toUpperCase() + id.slice(1);
        player.textContent = id;
        
        let compPlay = computerPlay();
        let computer_label = evalComputer(compPlay);
        computer_label = computer_label.charAt(0).toUpperCase() + computer_label.slice(1);

        computer.textContent = computer_label;

        let answer = evalAnswer(id);
        if (compPlay === answer){
            result.textContent = "It's a TIE 😒";
        }
        else if (compPlay == (answer+1)         ||
                (compPlay === 0 && answer === 2)){
            result.textContent = "You LOST 😢";
            cscore.textContent = eval(`${cscore.textContent} + 1`);
        }
        else {
            result.textContent = "You WON 😁";
            pscore.textContent = eval(`${pscore.textContent} + 1`);
        }
    });
});