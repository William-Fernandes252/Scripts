var readline = require('readline');
var reader = readline.createInterface({ input: process.stdin, output: process.stdout });

reader.on('line', (input) => {
    borders = Number(input);
    if (borders === 1) {
        console.log('Only one border!');
    }
    else if (borders > 1) {
        console.log('More than one border!');
    }
    else {
        console.log('No borders.');
    }
});