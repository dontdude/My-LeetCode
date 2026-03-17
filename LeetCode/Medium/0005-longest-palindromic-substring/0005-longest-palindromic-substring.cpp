class Solution {
    void expandFromCenter(int l, int r, string& lps, string& s) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        
        if(lps.size() < r - l - 1) {
            lps = s.substr(l + 1, r - l - 1);
        }
    }
public:
    string longestPalindrome(string s) {
        string lps = "";

        for(int i = 0; i < s.size(); i++) {
            expandFromCenter(i, i, lps, s);
            expandFromCenter(i, i + 1, lps, s);
        }

        return lps;
    }
};