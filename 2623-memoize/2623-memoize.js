/**
 * @param {Function} fn
 */
function memoize(fn) {
    const cache = {};    // declare a cache object
    return function(...args) {
        const key = JSON.stringify(args);    // making the two values (a, b), to use it as a key 

        //""in" operator is used to check if a property exists in an object or if an element exists in an array
        if(key in cache) {   
            return cache[key];
        } else {
            const result = fn(...args);
            cache[key] = result;
            return result;
        }
    }
}


/** 
 * let callCount = 0;
 * const memoizedFn = memoize(function (a, b) {
 *	 callCount += 1;
 *   return a + b;
 * })
 * memoizedFn(2, 3) // 5
 * memoizedFn(2, 3) // 5
 * console.log(callCount) // 1 
 */