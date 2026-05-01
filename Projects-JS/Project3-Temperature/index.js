function CtoF(x){
    return ((x * 9/5) + 32);
}
function CtoK(x){
    return Number(x)+273.15;
}
function FtoC(x){
    return Number((x - 32) * 5/9);
}
function FtoK(x){
    return Number((x - 32) * 5/9 + 273.15);
}
function KtoF(x){
    return Number((x - 273.15) * 9/5 + 32);
}
function KtoC(x){
    return Number(x)  - 273.15;
}
const answer = document.getElementById('answer');
const answertype = document.getElementById('answertype');
let input;
let typechosen;
document.getElementById('convert').onclick = function(){
    input = document.getElementById('input').value;
    Number(input);
    if(document.getElementById('type1').checked){
        answer.textContent = Math.round(CtoF(input));
        answertype.textContent = `Fahrenheit`;
    }else if(document.getElementById('type2').checked){
        answer.textContent = Math.round(FtoC(input));
        answertype.textContent = `Celsius`;
    }else if(document.getElementById('type3').checked){
        answer.textContent = Math.round(CtoK(input));
        answertype.textContent = `Kelvin`;
    }else if(document.getElementById('type4').checked){
        answer.textContent = Math.round(FtoK(input));
        answertype.textContent = `Kelvin`;
    }else if(document.getElementById('type5').checked){
        answer.textContent = Math.round(KtoC(input));
        answertype.textContent = `Celsius`;
    }else if(document.getElementById('type6').checked){
        answer.textContent = Math.round(KtoF(input));
        answertype.textContent = `Fahrenheit`;
    }
}
