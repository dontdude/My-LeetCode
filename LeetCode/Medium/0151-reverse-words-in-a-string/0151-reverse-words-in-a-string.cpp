class Solution {
    string reverseWord(int l, int r, string s) {
        if(l > r || l < 0)  return "";
        
        string reversedWord = " ";
        for(int i = r; i >= l; i--) {
            reversedWord.push_back(s[i]);
        }

        return reversedWord;
    }
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";
        int curr = 0, prev = -1;

        while(curr < n) {
            if(s[curr] == ' ') {  
                if(prev != -1) res += reverseWord(prev, curr - 1, s);
                prev = -1;
            } else if(prev == -1) {
                prev = curr;
            }

            curr++;
        }

        if(prev != -1) res += reverseWord(prev, curr - 1, s);
        
        reverse(res.begin(), res.end());

        res.pop_back();

        return res;
    }
};