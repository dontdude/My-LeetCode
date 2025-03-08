class Solution {
public:
    string expandFromCenter(int left, int right, string s) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }

        return s.substr(left + 1, right - left - 1);
    }
    string longestPalindrome(string s) {
        string res = "";
        
        for(int i = 0; i < s.size(); i++) {
            string odd = expandFromCenter(i, i, s);
            string even = expandFromCenter(i, i + 1, s);

            if(odd.size() > res.size()) {
                res = odd;
            }
            if(even.size() > res.size()) {
                res = even;
            }
        }

        return res;
    }
};