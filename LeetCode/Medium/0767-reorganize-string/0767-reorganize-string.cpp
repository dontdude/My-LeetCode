class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26, 0);
        int mxFreq = 0;
        int n = s.size();

        for(const char& c : s) {
            mxFreq = max(mxFreq, ++freq[c - 'a']);
        }

        if(mxFreq > (n + 1) / 2) return "";

        priority_queue<pair<int, char>> available;
        pair<int, char> waiting = {-1, '#'};

        for(int i = 0; i < 26; i++) {
            if(freq[i])  available.push({freq[i], char('a' + i)});
        }

        string result = "";

        while(!available.empty() || waiting.second != '#') {
            pair<int, char> curr = available.top();
            available.pop();

            result.push_back(curr.second);

            if(waiting.second != '#') {
                available.push({waiting.first, waiting.second});
                waiting = {-1, '#'};
            }

            if(curr.first > 1) waiting = {curr.first - 1, curr.second};
        }

        return result;
    }
};