class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_set<int> hashSet(nums.begin(), nums.end());

        for(int num : hashSet) {  //removes duplicate

            // Optimization: only traverse a group nexts (num + 1), if it is the first one (that is no num - 1 of this exsist)
            if(hashSet.find(num - 1) == hashSet.end()) {
                int curr_streak = 1;
                int curr_num = num;
                
                while(hashSet.find(curr_num + 1) != hashSet.end()) {    
                    curr_streak++;
                    curr_num = curr_num + 1;
                }

                res = max(res, curr_streak);
            }
        }

        return res;
    }
};