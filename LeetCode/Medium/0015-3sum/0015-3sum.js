/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let n = nums.length;
    var tripletSet = new Set();

    nums.sort();
    for(let i = 0; i < n - 2; i++) {
        let j = i + 1, k = n - 1;

        while(j < k) {
            let sum = nums[i] + nums[j] + nums[k];

            if(sum == 0) {
                tripletSet.add(JSON.stringify([nums[i], nums[j], nums[k]]));
                j++;
                k--;
            } else if(sum > 0) {
                k--;
            } else {
                j++;
            }
        } 
    }

    return Array.from(tripletSet, (triplet) => {
        return JSON.parse(triplet);
    });
};