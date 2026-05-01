let maxNum = 100, minNum = 1;
let number;
let attempts = 0;
let input;
console.log(number);
document.getElementById('play').onclick = function(){
    number = Math.floor(Math.random()*(maxNum-minNum)+minNum)+minNum;
    window.alert('Lets Begin!!!!!!!!!');
    input = window.prompt(`Guess the number between ${minNum} and ${maxNum}!`);
    if (isNaN(input))
        return 0;
    else if(input > maxNum || input<minNum)
        return 0;
    else{
        attempts=0;
        while(1){
            if (!isNaN(input) && (input < maxNum || input>minNum)){
                attempts++;
                if(input<number)
                    input = window.prompt(`TOO LOW`);
                else if (input>number)
                    input = window.prompt(`TOO HIGH`);
                else {
                    window.alert(`Congratulations, the number was ${number}, it took you ${attempts} attempts!!`);
                    break;
                }
            }
            else
                break;
        }
    }
}