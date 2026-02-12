class Solution {
    void expandFromCenter(int l, int r, string& res, string& s) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }

        if(res.size() < (r - l - 1)) {
            res = s.substr(l + 1, r - l - 1);
        }
    }
public:
    string longestPalindrome(string s) {
        string res = "";
        for(int i = 0; i < s.size(); i++) {
            expandFromCenter(i, i, res, s);  // odd len palidrome
            expandFromCenter(i, i + 1, res, s); // even len
        }

        return res;
    }
};