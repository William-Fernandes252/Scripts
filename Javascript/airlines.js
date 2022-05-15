const airline = 'TAP Air Portugal';
const plane = 'A320';

console.log(airline.indexOf('r'));
console.log(airline.lastIndexOf('r'));
console.log(airline.slice(4, 7));
console.log(airline.slice(0, airline.indexOf(' ')));
console.log(airline.slice(airline.lastIndexOf(' ') + 1));
console.log(airline.slice(-2));
console.log(airline.slice(1, -1));

const checkMiddleSeat = seat => {
    seatChar = seat.slice(-1);
    return seatChar === 'B' || seatChar === 'E';
};

console.log(checkMiddleSeat('11B'));

const fixName = name => {
    nameLower = name.toLowerCase();
    return nameLower[0].toUpperCase() + nameLower.slice(1);
};

console.log(fixName('WiLlIAm'));

const priceGB = '229,89£';
const priceUS = priceGB.replace('£', '$').replace(',', '.');
console.log(priceUS);

const announcement =
    'All passengers come to boarding door 23. Boarding door 23!';

console.log(announcement.replace(/door/g, 'gate'));

const neo = 'A320neo';
console.log(neo.includes('A320'));
console.log(neo.includes('Boeing'));
console.log(neo.startsWith('Air'));

const capitalizeName = name => {
    const names = name.split(' ');
    const capitalizedNames = [];
    names.forEach(name =>
        capitalizedNames.push(name.replace(name[0], name[0].toUpperCase()))
    );
    return capitalizedNames.join(' ');
};

console.log(capitalizeName('william fernandes dias'));

const maskCreditCard = cardNumber =>
    new String(cardNumber).slice(-4).padStart(cardNumber.length, '*');

console.log(maskCreditCard('23469483946'));

const flightsStr =
    '_Delayed_Departure;fao93766109;txl2133758440;11:25+_Arrival;bru0943384722;fao93766109;11:45+_Delayed_Arrival;hel7439299980;fao93766109;12:05+_Departure;fao93766109;lis2323639855;12:30';

const flights = [];
// for (const flight of flightsStr.split('+')) flights.push(flight);
// console.log(flights);
// const cleanedFlights = [];
// for (const registry of flights) {
//     let infoList = [];
//     for (const [i, info] of registry.split(';').entries()) {
//         switch (i) {
//             case 0:
//                 infoList.push(info.replace('_', '').replace('_', ' '));
//                 break;
//             case 1:
//             case 2:
//                 infoList.push(info.replace(/\d/g, '').toUpperCase());
//                 break;
//             case 3:
//                 infoList.push(`(${info})`);
//         }
//     }
//     cleanedFlights.push(infoList);
// }

// console.log(cleanedFlights);
// const messages = [];
// for (const flightInfo of cleanedFlights)
//     messages.push(
//         `${flightInfo[0].includes('Delayed') ? '🔴 ' : ''}${
//             flightInfo[0]
//         } from ${flightInfo[1]} to ${flightInfo[2]} ${flightInfo[3]}`
//     );

// for (const message of messages) console.log(message.padStart(40, ' '));

const getCode = str => str.replace(/\d/g, '').toUpperCase();

for (const flight of flightsStr.split('+')) {
    const [type, from, to, timestamp] = flight.split(';');
    console.log(
        `${type.includes('Delayed') ? '🔴' : ''}${type.replace(
            /_/g,
            ' '
        )} ${getCode(from)} ${getCode(to)} (${timestamp.replace(
            ':',
            'h'
        )})`.padStart(40, ' ')
    );
}
