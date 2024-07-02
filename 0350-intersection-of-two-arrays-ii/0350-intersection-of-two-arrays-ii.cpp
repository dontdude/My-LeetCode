class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        unordered_map<int, int> mp;
        for(auto n : nums2) {
            mp[n]++;
        }

        for(auto n : nums1) {
           if(mp.find(n) != mp.end()){
              res.push_back(n);
              mp[n]--;
              if(mp[n] == 0) {
                mp.erase(n);
              }
           }
        }

        return res;
    }
};