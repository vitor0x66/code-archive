let display = " ";
let visor = document.getElementById('visor');
function getInput(input){
    display += input;
    visor.textContent = display;
}
function clearDisplay(){
    display = "";
    visor.textContent = display;
}
function calculate(){
    try{
    display = eval(display);
    if (display == 'Infinity')
        throw Error("/ by 0");
    visor.textContent = display;
    }
    catch(error){
        display = 'Error';
        visor.textContent = display;
    }
}