class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();

        vector<pair<int, int>> nums;
        for(int i = 0; i < n; i++)  nums.push_back({nums2[i], nums1[i]});

        sort(nums.rbegin(), nums.rend());

        priority_queue<int, vector<int>, greater<int>> pq;  
        long long res = 0, sum = 0;
        for(int i = 0; i < n; i++){
            sum += nums[i].second;
            pq.emplace(nums[i].second);

            if(pq.size() > k){
                sum -= pq.top();
                pq.pop();
            }

            if(pq.size() == k)  res = max(res, (long long)sum * nums[i].first);
        }

        return res;
    }
};