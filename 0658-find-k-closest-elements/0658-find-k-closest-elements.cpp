class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        vector<int> res;
        
        int i = pos - 1, j = pos;
        while(k--) {
            int d1 = i >= 0 ? x - arr[i] : INT_MAX;
            int d2 = j < arr.size() ? arr[j] - x : INT_MAX;
            
            if(d1 <= d2) {
                res.push_back(arr[i--]);
            } else {
                res.push_back(arr[j++]);
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};