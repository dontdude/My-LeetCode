class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p = 1, i = 0, j = 0;
        string res = "";
        while(i < word1.size() && j < word2.size()){
            if(p)  res += word1[i++];
            else res += word2[j++];
            p ^= 1;
        }
        res += word1.substr(i);
        res += word2.substr(j);

        return res;
    }
};