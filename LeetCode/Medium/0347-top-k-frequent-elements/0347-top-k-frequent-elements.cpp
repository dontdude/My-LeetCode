class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hashMap;
        for(int num : nums) {
            hashMap[num]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto& it : hashMap) {
            int freq = it.second;
            int num = it.first;

            if(pq.size() < k) {
                pq.push({-freq, num});
            } else if(freq > -pq.top().first) {
                pq.pop();
                pq.push({-freq, num});
            } 
        }

        vector<int> result;
        while(!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }
};