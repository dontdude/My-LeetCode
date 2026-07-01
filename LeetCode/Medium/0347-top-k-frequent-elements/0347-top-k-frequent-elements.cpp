class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        priority_queue<pair<int, int>> pq;

        int candidate = nums[0], vote = 1;

        for(int i = 1; i < nums.size(); i++) {
            if(candidate != nums[i]) {
                pq.push({-vote, candidate});
                if(pq.size() > k)  pq.pop();

                candidate = nums[i];
                vote = 1;
            } else {
                vote++;
            }
        }

        pq.push({-vote, candidate});
        if(pq.size() > k)  pq.pop();

        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};