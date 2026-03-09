class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int, pair<int, int>>> minheap;   // {-sum, {i, j}}

        for(int i = 0; i < nums1.size(); i++) {
            int sum = nums1[i] + nums2[0];
            minheap.push({-sum, {i, 0}});
        }

        vector<vector<int>> res;

        while(!minheap.empty() && res.size() < k) {
            int i = minheap.top().second.first;
            int j = minheap.top().second.second;
            minheap.pop();

            res.push_back({nums1[i], nums2[j]});

            if(j + 1 < nums2.size()) {
                int sum = nums1[i] + nums2[j + 1];
                minheap.push({-sum, {i, j + 1}});
            }
        }

        return res;
    }
};