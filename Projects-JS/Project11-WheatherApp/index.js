//site: https://www.weatherapi.com/my/
const API_KEY = '3efbb45d50024d32ab5141346241309';


document.getElementById("button").addEventListener('click', event => {
    getPlace().then(place => fetchData(place));
})


function getPlace(){
    const cityname = document.getElementById('name');
    search = String(cityname.value);

    search = search.trim();
    search = search.replaceAll(" ", "+");

    console.log(`Cityname: ${search}`);
    
    return new Promise((resolve, reject) => {
        resolve(search);
    });
}

async function fetchData(place){
    try{
        const initRequest = await fetch(`http://api.weatherapi.com/v1/current.json?key=${API_KEY}&q=${place}&aqi=yes&lang=en`);
        let request;

        if (!initRequest.ok)
            throw new Error("Fail to fetch");
        
        request = await initRequest.json();
        console.log(request);
        request = request.current;
        console.log(request);

        let temp; 
        let humidity; 
        let airquality;
        let condition;
        temp = request.temp_c;
        humidity = request.humidity;
        condition = String(request.condition.text).trim();

        if (request.air_quality["us-epa-index"]<4){
            airquality = 'Good';
        }
        else if (request.air_quality["us-epa-index"]>3 && request.air_quality["us-epa-index"]<7){
            airquality = 'Medium';
        }
        else if (request.air_quality["us-epa-index"]>6 && request.air_quality["us-epa-index"]< 10){
            airquality = 'Bad';
        }
        else
            airquality = 'Very Bad';
            
        console.log(airquality); 
        console.log(temp);
        console.log(condition);
        console.log(humidity);

        document.getElementById("condition").textContent = condition;
        document.getElementById("temp").textContent = temp + " °C";
        document.getElementById("airquality").textContent = airquality;
        document.getElementById("humidity").textContent = humidity + "%";

    }
    catch(error){
        console.error(error);
        window.alert(error);
        location.reload();
    }
}