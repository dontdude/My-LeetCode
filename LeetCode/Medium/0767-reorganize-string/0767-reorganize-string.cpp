class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        
        for(const auto& c: s) {
            if(++count[c - 'a'] > (n + 1) / 2)  return "";
        }

        priority_queue<pair<int, char>> available;
        queue<pair<int, pair<int, char>>> waiting;

        for(int i = 0; i < 26; i++) {
            if(count[i]) available.push({count[i], 'a' + i});
        }

        string res = "";
        int time = 0;
        while(!available.empty() || !waiting.empty()) {
             while(!waiting.empty() && waiting.front().first <= time) {
                available.push(waiting.front().second);
                waiting.pop();
            }
            
            if(!available.empty()) {
                res.push_back(available.top().second);
                int newAvailableCount = available.top().first - 1;
                if(newAvailableCount) waiting.push({time + 2, {newAvailableCount, available.top().second}});
                available.pop();
            }

            time++;
        }

        return res;
    }
};