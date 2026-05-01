let contador = 0;
let num = document.getElementById("num");
num.textContent = contador;
document.getElementById("decrease").onclick=function(){
    contador--;
    num.textContent = contador;
}
document.getElementById("increase").onclick=function(){
    contador++;
    num.textContent = contador;
}
document.getElementById("reset").onclick = function(){
    contador = 0;
    num.textContent = contador;
}