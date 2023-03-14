class Solution {
public:
    void backtrack(int i, vector<int>& cur, vector<int>& nums, vector<vector<int>>& res){
        // Same "take it" or "leave it" approach, 
        // but here when we leave a number, than we also leave all its duplicates too
        // because the "take it" case is able to consider all that element subsets
        if(i == nums.size()) {
            res.push_back(cur);
            return;
        }

        cur.push_back(nums[i]); 
        backtrack(i + 1, cur, nums, res);       // take it
        
        cur.pop_back();
        while(i+1 < nums.size() && nums[i] == nums[i+1])  i++;   // for duplicates

        backtrack(i + 1, cur, nums, res);      // leave it, (all it's duplicates too)
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> res;  
        vector<int> cur;
        sort(nums.begin(), nums.end());

        backtrack(0, cur, nums, res);

        return res;
    }
};