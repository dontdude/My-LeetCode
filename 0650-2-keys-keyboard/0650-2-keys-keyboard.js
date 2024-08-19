/**
 * @param {number} n
 * @return {number}
 */
var minSteps = function(n) {
    let highestFactor = Math.floor(Math.sqrt(n));
    for(let i = 2; i <= highestFactor; i++) {
        if(n % i === 0) {
          return minSteps(n / i) + i;  
        }
    }

    return n === 1 ? 0 : n;
};