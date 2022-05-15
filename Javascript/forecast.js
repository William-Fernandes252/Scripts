const temps = [12, -5, 5, 0, 4];

const printForecast = function (data) {
    for (let i = 0; i < data.length; i++) {
        console.log(`${data[i]}ºC in ${i} days.`);
    }
};

printForecast(temps);
