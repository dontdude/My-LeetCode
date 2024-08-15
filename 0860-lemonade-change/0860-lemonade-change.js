/**
 * @param {number[]} bills
 * @return {boolean}
 */
var lemonadeChange = function(bills) {
    let five = 0, ten = 0;
    for(let i = 0; i < bills.length; i++) {
        let bill = bills[i];
         if(bill === 5) {
            five++;
        } else if(bill === 10) {
            if(five > 0) {
                five--;
                ten++;
            } else {
               return false;
            }
        } else {
            if(five > 0 && ten > 0) {console.log(five, ten, "1")
                five--;
                ten--;
            } else if(five > 2) {console.log(five, ten, "2")
                five -= 3;
            } else {
                return false
            }
        }
    }

    return true;
};