/**
 * @param {Function[]} functions
 * @param {number} n
 * @return {Function}
 */
var promisePool = async function(functions, n) {
    return new Promise((resolve) => {
        let i = 0; 
        let inProgress = 0;
        callback();

        function callback() {                                     // recursive function
            if(i === functions.length && inProgress == 0){        // all promise in functions encountere && all promise are resolved
                resolve();                      
            }

            while(i < functions.length && inProgress < n){
                functions[i++]()
                   .then(() => {                                  // what happens when the promise at current index i gets resolved
                       inProgress--;
                       callback();                               // calling callback, since a promise is resolved
                   });
                inProgress++;
            }
        }
    });
};

/**
 * const sleep = (t) => new Promise(res => setTimeout(res, t));
 * promisePool([() => sleep(500), () => sleep(400)], 1)
 *   .then(console.log) // After 900ms
 */