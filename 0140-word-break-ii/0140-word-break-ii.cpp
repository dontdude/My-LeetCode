class Solution {
public:
    void solve(int start, string curr, vector<string>& res, string s, unordered_set<string>& dictionary) {
        if(start == s.size()) {
            res.push_back(curr);
            return;
        }

        for(int i = start; i < s.size(); i++) {
           string word = s.substr(start, i - start + 1);
           if(dictionary.find(word) != dictionary.end()) {
            string temp = curr;
            if(curr.size() > 0) {
                curr += " ";
            }
            curr += word;

            solve(i + 1, curr, res, s, dictionary);
            
            curr = temp;  // backtrack
           }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        unordered_set<string> dictionary(wordDict.begin(), wordDict.end());
        solve(0, "", res, s, dictionary);
        return res;
    }
};