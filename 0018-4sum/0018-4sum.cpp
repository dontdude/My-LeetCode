class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>> st;

        sort(nums.begin(), nums.end());
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                int k = j + 1, l = n - 1;
                long long rest = long(target) - nums[i] - nums[j];
                while(k < l) {
                  if(nums[k] + nums[l] == rest) {
                    st.insert({nums[i], nums[j], nums[k], nums[l]});
                    if(nums[k] == nums[k + 1]) {
                        k++;
                    } else {
                        l--;
                    }
                  } else if(nums[k] + nums[l] < rest) {
                    k++;
                  } else {
                    l--;
                  }
                }
            }
        }

        vector<vector<int>> res;
        for(auto s : st) {
            res.push_back(s);
        }

        return res;
    }
};