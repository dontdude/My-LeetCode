class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for(auto ch : s) {
            freq[ch]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto fq : freq) {
            pq.push({fq.second, fq.first});
        }

        string res = "";
        while(!pq.empty()) {
            auto currCh = pq.top();   pq.pop();
            int count = currCh.first;
            while(count--) {
                res += currCh.second;
            } 
        }

        return res;
    }
};