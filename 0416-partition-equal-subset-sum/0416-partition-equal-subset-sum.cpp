class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num: nums) sum += num;

        // since sum1 = sum2, and sum1 + sum2 = sum.. so sum/2 = sum1 = sum2
        if(sum & 1) {
            return false;  // if sum is odd.. can't devide into 2 equal sum subset
        }


        // creating a set of sum of all the subsets of nums, if any subset sum is sum/2, return true

        set<int> memo;
        memo.insert(0);   // no elem subset sum
        // If nums = {1, 5} -> subset sums: {0} -> {0, 0 + 1} -> {0, 1, 0 + 5, 1 + 5} or {0, 1, 5, 6}

        for(auto num: nums) {
            set<int> newMemo = memo;         // Imp:  pushing directly to the memo set which you are iterating cause TLE for some cases.
            for(auto subsums: newMemo) {
                int newSubSum = subsums + num;
                if(newSubSum == sum / 2) {
                    return true;
                }

                memo.insert(newSubSum);
            }
        }

        return false;
    }
};