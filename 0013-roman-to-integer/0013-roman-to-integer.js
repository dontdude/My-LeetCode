/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const romanMapping = {
        I : 1,
        V : 5, 
        X : 10,
        L : 50,
        C : 100,
        D : 500,
        M : 1000,
    }

    let prev = romanMapping[s[s.length - 1]];
    let sum = prev;

    for(let i = s.length - 2; i >= 0; i--) {
       let curr = romanMapping[s[i]];
       prev > curr ? sum -= curr : sum += curr;
       prev = curr;
    }

    return sum;
};