/**
 * @param {Function} fn
 * @param {number} t
 * @return {Function}
 */
var timeLimit = function(fn, t) {
    const endsInTimeTPromise = new Promise((resolve, reject) => {    
        setTimeout(() => {
            reject("Time Limit Exceeded");
        }, t);
    });
    
	return async function(...args) {
        // the promise.race takes a list of promise and returns a promise, so that it immeaditely stops and returns the result of the promise whose execution is finished first in given list
        const givenPromise = fn(...args);
        return racePromise = Promise.race([endsInTimeTPromise, givenPromise]);
    }
};

/**
 * const limited = timeLimit((t) => new Promise(res => setTimeout(res, t)), 100);
 * limited(150).catch(console.log) // "Time Limit Exceeded" at t=100ms
 */