const oneWord = function (str) {
    return str.replace(/ /g, '').toLowerCase();
};

const upperFirstWord = function (str) {
    const [first, ...others] = str.split(' ');
    return [first.toUpperCase(), ...others].join(' ');
};

const transform = function (str, fn) {
    return fn(str);
};

console.log(
    transform(
        'JavaScript is actually a pretty awesome language.',
        upperFirstWord
    )
);
console.log(
    transform('JavaScript is actually a pretty awesome language.', oneWord)
);

// Partial application
const addTax = (rate, value) => value + value * rate;
console.log(0.1, 100);

const addVAT = addTax.bind(null, 0.23);
console.log(addVAT(100));

const buildAddTax = rate => value => value + value * rate;
const addIR = buildAddTax(0.06);
console.log(addIR(100));

// IIFE
(() => console.log('That function will NEVER run again!'))();

// Closures

const secureBooking = function () {
    let passengerCount = 0;

    return function () {
        passengerCount++;
        console.log(`${passengerCount} passengers.`);
    };
};

const booker = secureBooking();

booker();
booker();
booker();

/*
A closure is basically the access of a function to the execution context where it was created, even after it's is popped out of the call stack. So, the booker function still have access to passengerCount after the execution of secureBooking. 
*/

console.dir(booker);

// Example #1
let f;

const g = function () {
    const a = 23;
    f = function () {
        console.log(a * 2);
    };
};

const h = function () {
    const b = 777;
    f = function () {
        console.log(b * 2);
    };
};

g();
f();
console.dir(f);

h();
f();
console.dir(f);

// Example #2
const boardPassengers = function (n, wait) {
    const perGroup = n / 3;

    setTimeout(() => {
        console.log(`We are now boarding all ${n} passengers`);
        console.log(`There are 3 groups, each with ${perGroup} passengers.`);
    }, wait * 1000);

    console.log(`Will start boarding in ${wait} seconds...`);
};

let perGroup = 1000;
/* Variables acessed through a closure have priority on lookups in the scope chain. */
boardPassengers(180, 3);

// Coding challenge #2

/*
Take the IIFE below and at end of the function, attach an event listener that changes the color of the selected h1 element ('header') to blue, whenever the body of the page is clicked. Do NOT select the h1 element again!

Good LUCK 😀
*/

(function () {
    const header = document.querySelector('h1');
    header.style.color = 'red';

    document.querySelector('body').addEventListener('click', function () {
        header.style.color = 'blue';
    });
})();
