'use strict';

let manager = 'Dwight';
const week = ['sun', 'mon', 'tue', 'wed', 'thu', 'fri', 'sat'];
const restaurant = {
    name: 'Classico Italiano',
    /* ES6 enhanced object literals */
    manager,
    location: 'Via Angelo Tavanti 23, Firenze, Italy',
    categories: ['Italian', 'Pizzeria', 'Vegetarian', 'Organic'],
    starterMenu: ['Focaccia', 'Bruschetta', 'Garlic Bread', 'Caprese'],
    mainMenu: ['Pizza', 'Pasta', 'Risotto'],
    order: function (starterId, mainId) {
        return [this.starterMenu[starterId], this.mainMenu[mainId]];
    },
    openingHours: {
        [week[4]]: {
            open: 12,
            close: 22,
        },
        [week[5]]: {
            open: 11,
            close: 23,
        },
        [week[6]]: {
            open: 0,
            close: 24,
        },
    },
    orderDelivery: function ({
        starterId = 1,
        mainId = 0,
        time = '20:00',
        address,
    }) {
        console.log(
            `Order received! ${this.mainMenu[mainId]} will be delivered to ${address} at ${time}`
        );
    },
    /* ES6 enhanced object literals */
    orderPasta(ing1, ing2, ing3) {
        console.log(
            `Here is your delicious pasta with ${ing1} and ${ing2} and ${ing3}!`
        );
    },
    orderPizza: function (mainIngredient, ...otherIngredients) {
        console.log(mainIngredient);
        console.log(otherIngredients);
    },
};

// Array destructuring
let arr = [2, 3, 4];
let [x, y, z] = arr;
console.log(x, y, z);
let [primary, , secondary] = restaurant.categories;
console.log(primary, secondary);

// Swap values between variables
[secondary, primary] = [primary, secondary];
console.log(primary, secondary);

// Unpack returned list
let [starter, main] = restaurant.order(1, 2);
console.log(starter, main);

// Nested destructuring
let nested = [2, 3, [4, 5]];
let [i, , [j, k]] = nested;
console.log(i, j, k);

// Default values
let [p, q, r = 1] = [8, 9];
console.log(p, q, r);

// Object destructuring
let { name, categories, openingHours } = restaurant;
console.log(name, categories, openingHours);

// Destruct in variables with names different from the properties
let {
    name: restaurantName,
    categories: tags,
    openingHours: hours,
} = restaurant;
console.log(restaurantName, tags, hours);

// Default values
let { menu = [], starterMenu: starters = [] } = restaurant;
console.log(menu, starters);

// Mutating variables
let a = 111;
let b = 999;
let obj = { a: 23, b: 7, c: 14 };
({ a, b } = obj); /* Must have the parentesis */
console.log(a, b);

// Nested distructuring
let {
    fri: { open: o, close: c },
} = openingHours;
console.log(o, c);

restaurant.orderDelivery({
    time: '22:30',
    address: 'Via del Sole, 21',
    mainId: 2,
    starterId: 2,
});

// Spread operator
let numbers = [7, 8, 9];
let l = [1, 2, ...numbers];
console.log(l);

let newMenu = [...restaurant.mainMenu, 'Gnocci'];
console.log(newMenu);

// Copy an array
let mainMenuCopy = [...restaurant.mainMenu];

// Join two arrays
let fullMenu = [...restaurant.starterMenu, ...restaurant.mainMenu];

// Spread to array elements as arguments
// const ingredients = [
//     prompt("Lets's make pasta! Ingredient 1?"),
//     prompt('Ingredient¦ 2?'),
//     prompt('Ingredient 3?'),
// ];
// restaurant.orderPasta(...ingredients);

// Objects
const newRestaurant = { ...restaurant, founder: 'Guiseppe', foudedIn: 1980 };
console.log(newRestaurant);

// Copy an object
const restaurantCopy = { ...restaurant };
restaurantCopy.name = 'Ristorante Roma';
console.log(restaurant.name);
console.log(newRestaurant.name);

// Rest pattern
const [v, u, ...others] = [1, 2, 3, 4, 5];
console.log(v, u, others);

const [pizza, , risotto, ...otherOptions] = [
    ...restaurant.mainMenu,
    ...restaurant.starterMenu,
]; /* Assignments can have only one destructuring pattern */
console.log(pizza, risotto, otherOptions);

// Objects
let { sat, ...weekdays } = restaurant.openingHours;
console.log(sat, weekdays);

// Functions
const add = function (...numbers) {
    let sum = 0;
    numbers.forEach(number => (sum += number));
    return sum;
};
console.log(add(1, 2, 3, 4));

arr = [3, 4, 5];
console.log(add(...arr));

restaurant.orderPizza('mushrooms', 'onion', 'olives', 'spinach');

// Short-circuiting

/* OR (||): returns the first truthy or the last falsy value */
console.log(3 || 'Jonas');
console.log(undefined || 0 || '' || 'Hello');
let guests = restaurant.numGuests || 10;
console.log(guests);

/* AND (&&): return the first falsy or the last truthy value */
console.log(0 && 'Jonas');
console.log('Hello' && 23 && null && true);
restaurant.orderPizza && restaurant.orderPizza('mushrooms', 'onion', 'tomato');

// Nullish coalescing operator: Evaluates only nullish values (like 'null' and 'undefined') to false (and not 0 or '')
restaurant.numGuests = 0;
guests = restaurant.numGuests ?? 10;
console.log(guests);

// Logical assignment operator
const pub1 = {
    name: 'La Pizza',
    // numGuests: 20,
    numGuests: 0,
};
const pub2 = {
    name: 'Capri',
    owner: 'Giovanni Rossi',
};

// ||= and ??=
pub1.numGuests ??= 10;
pub2.numGuests ||= 10;
console.log(pub1, pub2);

// &&=
pub1.owner &&= 'anonymous';
pub2.owner &&= 'anonymous';
console.log(pub2.owner);

// For of
menu = [...restaurant.starterMenu, ...restaurant.mainMenu];
for (const [id, item] of menu.entries()) console.log(`${id + 1}: ${item}`);

// Optional chaining

/* On properties */
console.log(restaurant.openingHours?.mon?.open);

for (const day of week) {
    let openHr = restaurant.openingHours[day]?.open ?? 'closed';
    console.log(`On ${day} we open at ${openHr}.`);
}

/* On methods */
console.log(restaurant.order?.(0, 1) ?? 'This method does not exist.');
console.log(restaurant.orderRisotto?.(0, 1) ?? 'This method does not exist.');

// Property names
for (let day of Object.keys(openingHours)) {
    console.log(day);
}
console.log(`We are open on ${Object.keys(openingHours)}`);

// Property values
console.log(Object.values(openingHours));

// Entire object
console.log(Object.entries(openingHours));

// Sets
for (const [day, { open, close }] of Object.entries(openingHours))
    console.log(`On ${day} we open at ${open} and close at ${close}.`);

const ordersSet = new Set(['Pasta', 'Pizza', 'Risotto', 'Pasta', 'Pizza']);
console.log(ordersSet, ordersSet.size);
console.log(ordersSet.has('Bread'));
ordersSet.add('Garlic Bread');
console.log(ordersSet);
ordersSet.delete('Pizza');
console.log(ordersSet);
// ordersSet.clear();

// Sets example
const staff = [
    'Waiter',
    'Chef',
    'Waiter',
    'Manager',
    'Chef',
    'Waiter',
    'Cooker',
    'Baker',
];
const roles = [...new Set(staff)];
console.log(roles);

// Maps
const pub = new Map();
pub.set('name', "Moow's");
pub.set(1, 'Firenze, Italy');
pub.set(2, 'Lisbon, Portugal');
pub.set('categories', ['Italy', 'Pizzaria', 'Vegetarian', 'Organic'])
    .set('open', 11)
    .set('close', 23)
    .set(true, 'We are open 😊')
    .set(false, 'We are closed 😕');

console.log(pub.get('name'));

const time = 21;
let state = pub.get(time >= pub.get('open') && time <= pub.get('close'));
console.log(state);

console.log(pub.has('categories'));
pub.delete(2);

const hoursMap = new Map(Object.entries(openingHours));
console.log(hoursMap);
