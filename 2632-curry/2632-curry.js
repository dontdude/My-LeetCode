/**
 * @param {Function} fn
 * @return {Function}
 */
// How does currying work? csum(1)(2) means csum() functions is called with parameter 1, which it returns a functions, to which we are passing parameter 2
var curry = function(fn) {
    return function curried(...args) {
       if(args.length < fn.length){
           return function(...args2){
               return curried(...args, ...args2);
           }
       }
       return fn(...args);
    };
};

/**
 * function sum(a, b) { return a + b; }
 * const csum = curry(sum);    // calling curry function with a parameter function, which returns a function named as csum
 * csum(1)(2) // 3   // csum(1)(2) may mean that calling the functioin csum(1) which also returns a functions to which we are passing 2
 */