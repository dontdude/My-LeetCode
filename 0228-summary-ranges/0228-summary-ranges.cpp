class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0, n = nums.size();

        while(i < n){
           string range = to_string(nums[i]);
           while(i+1 < n && nums[i+1] == nums[i] + 1)  i++;
           if(range != to_string(nums[i]))  range += "->" + to_string(nums[i]);
           
           res.push_back(range);
           i++;
        }

        return res;
    }
};