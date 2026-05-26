class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lower(26, 0), upper(26, 0);

        for(const char& c : word) {
            if('a' <= c && c <= 'z') lower[c - 'a']++;
            else upper[c - 'A']++;
        }

        int res = 0;
        for(int i = 0; i < 26; i++) {
            if(lower[i] && upper[i])  res++;
        }

        return res;
    }
};