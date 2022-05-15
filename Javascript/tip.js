"using strict";

const { log } = require("console");

const calcTip = function (bill) {
  let tipRatio = 50 <= bill && bill <= 300 ? 0.15 : 0.2;
  return bill * tipRatio;
};

const calcTotal = (bill) => bill + calcTip(bill);

const total = [];

bills = prompt("Enter a list of bills.").trim().split(" ");
for (let i = 0; i < bills.length; i++) {
  total.push(calcTotal(Number(bills[i])));
}
console.log(total);
