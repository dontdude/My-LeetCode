class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int pos = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
        deque<int> dq;
        
        int i = pos - 1, j = pos;
        while(k--) {
            int d1 = i >= 0 ? x - arr[i] : INT_MAX;
            int d2 = j < arr.size() ? arr[j] - x : INT_MAX;
            
            if(d1 <= d2) {
                dq.push_front(arr[i--]);
            } else {
                dq.push_back(arr[j++]);
            }
        }
        
        vector<int> res;
        while(!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        
        return res;
    }
};