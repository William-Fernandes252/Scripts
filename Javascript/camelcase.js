function undersCoreToCamel(str) {
    // Challenge of a JS course
    lines = str.trim().split('\n');
    const camelLines = [];
    for (const [i, line] of lines.entries()) {
        words = [];
        for (const [j, word] of line.split('_').entries()) {
            lowerCaseWord = word.trim().toLowerCase();
            words.push(
                j === 0
                    ? lowerCaseWord
                    : lowerCaseWord[0].toUpperCase() + lowerCaseWord.slice(1)
            );
        }
        camelLines.push(words.join('').padEnd(20, ' ') + '✅'.repeat(i + 1));
    }
    return camelLines;
}

document.addEventListener('DOMContentLoaded', function () {
    document.body.append(document.createElement('textarea'));
    document.body.append(document.createElement('button'));

    document.querySelector('button').addEventListener('click', () => {
        output = undersCoreToCamel(document.querySelector('textarea').value);
        for (let identifier of output) console.log(identifier);
    });
});
