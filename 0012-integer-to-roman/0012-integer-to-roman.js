/**
 * @param {number} num
 * @return {string}
 */

const ITR = {
    1: "I",
    5: "V",
    10: "X",
    50: "L",
    100: "C",
    500: "D",
    1000: "M",
}

var intToRoman = function(num) {
    let res = "";
    let decimalPlace = 1;

    while(num > 0) {
       let r = (num % 10);
       
       if(r < 4) {
        while(r--)  res = ITR[decimalPlace] + res;
       } else if(r === 4) {
        res = ITR[decimalPlace] + ITR[5 * decimalPlace] + res;
       } else if(r < 9) {
        let ct = r - 5;
        while(ct--) res = ITR[decimalPlace] + res;
        res = ITR[5 * decimalPlace] + res;
       } else if(r == 9) {
        res = ITR[decimalPlace] + ITR[10 * decimalPlace] + res;
       } else {
        res = ITR[10 * decimalPlace] + res;
       }

       decimalPlace *= 10;
       num = Math.floor(num / 10);
    }

    return res;
};