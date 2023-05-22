class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int> h;
        
        for(int i = 0; i < nums.size(); i++){
            h[nums[i]]++;
        }
        
        vector<pair<int, int>> v;
        
        for(auto e : h){
            v.push_back({e.second, e.first});
        }
        
        sort(v.begin(), v.end());
        
        int n = v.size() - 1;
        vector<int> res;
       
        while(k--)  res.push_back(v[n--].second);        
        
        return(res);
    }
};