class Solution {
public:
    bool isValidPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    void dfs(int start, string s, vector<string>& cur, vector<vector<string>>& res) {
        if(start >= s.size()) {
            res.push_back(cur);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            string partS = s.substr(start, i - start + 1);
            if(isValidPalindrome(partS)) {
                cur.push_back(partS);
                dfs(i + 1, s, cur, res);
                cur.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(0, s, cur, res);
        return res;
    }
};