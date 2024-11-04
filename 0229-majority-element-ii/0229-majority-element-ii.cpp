class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> candidates(2, 0), votes(2, 0);
        
        for(int i = 0; i < n; i++) {
            if(votes[0] <= 0 && candidates[1] != nums[i]) {
                votes[0] = 1;
                candidates[0] = nums[i];
            } else if(votes[1] <= 0 && candidates[0] != nums[i]) {
                votes[1] = 1;
                candidates[1] = nums[i];
            } else if(nums[i] == candidates[0]) {
                votes[0]++;
            } else if(nums[i] == candidates[1]) {
                votes[1]++;
            } else {
                votes[0]--;
                votes[1]--;
            }
        }

        vector<int> count(2, 0), res;
        for(int i = 0; i < n; i++) {
            if(nums[i] == candidates[0]) {
                count[0]++;
            } else if(nums[i] == candidates[1]) {
                count[1]++;
            }
        }

        if(count[0] > n/3)  res.push_back(candidates[0]);
        if(count[1] > n/3)  res.push_back(candidates[1]);

        return res;
    }
};