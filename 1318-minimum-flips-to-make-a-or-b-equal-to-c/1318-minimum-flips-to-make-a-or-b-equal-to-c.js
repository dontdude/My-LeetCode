/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number}
 */
var minFlips = function(a, b, c) {
    var res = 0;
    for(var i = 0; i < 32; i++){
       var mask = (1<<i);
       
       if((mask & c) && !((mask & a) || (mask & b)))   res++;
       if(!(mask & c)){
           if(mask & a)  res++;
           if(mask & b)  res++;
       } 
    }

    return res;
};