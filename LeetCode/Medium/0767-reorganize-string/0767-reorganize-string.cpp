class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> count(26, 0);
        for(int i = 0; i < n; i++) {
            count[s[i] - 'a']++;
        }

        priority_queue<pair<int, char>> pq;
        int mx = 0, sum = 0;
        for(int i = 0; i < 26; i++) {
            if(count[i] > 0) {
                char ch = (char)('a' + i);
                pq.push({count[i], ch});

                mx = max(mx, count[i]);
                sum += count[i];
            }
        }

        if(mx > (sum + 1) / 2) {
            return "";
        }

        pair<int, char> hold = {-1, '-'};

        string res = "";
        while(pq.empty() == false) {
            auto top = pq.top();
            pq.pop();

            res += top.second;

            if(hold.first != -1) {
                pq.push(hold);
                hold = {-1, '-'};
            }

            if(top.first - 1 > 0) {
                hold = {top.first - 1, top.second};
            }
        }

        if(hold.first != -1) {
            res += hold.second;
        }

        return res;
    }
};