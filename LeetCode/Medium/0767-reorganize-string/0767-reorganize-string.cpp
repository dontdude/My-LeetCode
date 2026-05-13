class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        
        for(const auto& c: s) {
            if(++count[c - 'a'] > (n + 1) / 2)  return "";
        }

        priority_queue<pair<int, char>> available;
        pair<int, char> waiting = {-1, ' '};

        for(int i = 0; i < 26; i++) {
            if(count[i]) available.push({count[i], 'a' + i});
        }

        string res = "";
        while(!available.empty() || waiting.first != -1) {
            pair<int, char> newAvailable = {-1, ' '};
            if(waiting.first != -1) {
                newAvailable = waiting;
                waiting = {-1, ' '};
            }
            
            if(!available.empty()) {
                res.push_back(available.top().second);
                int newAvailableCount = available.top().first - 1;
                if(newAvailableCount) waiting = {newAvailableCount, available.top().second};
                available.pop();
            }

            if(newAvailable.first != -1) {
                available.push(newAvailable);
            } 
        }

        return res;
    }
};