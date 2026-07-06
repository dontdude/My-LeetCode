class Solution {
    bool isValidAns(vector<int>& nums, int& k, int& possibleAns) {
        int currSubarr = 0;
        int reqK = 1;

        for(const int& num : nums) {
            if(currSubarr + num <= possibleAns) {
                currSubarr += num;
            } else {
                reqK++;
                currSubarr = num;
            }
        }
        
        return k >= reqK;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int minAns = 0, maxAns = 0;

        for(const int& num : nums) {
            minAns = max(minAns, num);
            maxAns += num;
        }

        while(minAns < maxAns) {
            int possibleAns = minAns + (maxAns - minAns) / 2;

            if(isValidAns(nums, k, possibleAns)) {
                maxAns = possibleAns;
            } else {
                minAns = possibleAns + 1;
            }
        }

        return minAns;
    }
};