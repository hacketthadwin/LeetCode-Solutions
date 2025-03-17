/**
 * @param {string} sequence
 * @param {string} word
 * @return {number}
 */
var maxRepeating = function(sequence, word) {
    let cnt = 0;
    let currcnt = 0;
    for (let i = 0; i < sequence.length; i++) {
        let j = 0;
        let a = 0;
        while (i + a < sequence.length && sequence[i + a] === word[a % word.length]) {
            a++;
            if (a % word.length === 0) {
                currcnt++;
            }
        }
        cnt = Math.max(cnt, currcnt);
        currcnt = 0;
    }
    return cnt;
};