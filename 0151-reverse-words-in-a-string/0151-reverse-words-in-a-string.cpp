class Solution {
public:
    string reverseWords(string s) {
        string res = "", word = "";
        for(int i = s.size() - 1; i >= 0; i--) {
           if(s[i] == ' ') {
             res += (res.size() > 0 && word.size() > 0) ? " " + word : word;
             word = "";
           } else {
             word = s[i] + word;
           }
        }
        
        if(word.size() > 0) {
            res += res.size() > 0 ? " " + word : word;
        }

        return res;
    }
};