function getClock(){
    const date = new Date();
    const hour = date.getHours();
    const min = date.getMinutes();
    const sec = date.getSeconds();
    const time = `${hour.toString().padStart(2,0)}:${min.toString().padStart(2,0)}:${sec.toString().padStart(2,0)}`;
    const day = date.getDate();
    const month = (date.getMonth())+1;
    const year = date.getFullYear();
    const fulldate = `${day.toString().padStart(2,0)}/${month.toString().padStart(2,0)}/${year.toString().padStart(2,0)}`;
    document.getElementById(`time`).textContent = time;
    document.getElementById(`date`).textContent = fulldate;
}
getClock();
setInterval(getClock, 1000);