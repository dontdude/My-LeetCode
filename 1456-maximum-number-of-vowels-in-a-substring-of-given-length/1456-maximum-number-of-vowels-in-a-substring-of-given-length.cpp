class Solution {
public:
    int maxVowels(string s, int k) {
        int n = s.size();
        vector<int> vowel(n, 0);
        for(int i = 0; i < n; i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')  vowel[i] = 1;
            if(i)  vowel[i] += vowel[i-1];
        }

        int res = 0;
        for(int i = k - 1; i < n; i++){
            res = max(res, vowel[i] - (i - k < 0 ? 0 : vowel[i - k]));
        }

        return res;
    }
};