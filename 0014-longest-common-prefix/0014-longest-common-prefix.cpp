class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        sort(strs.begin(), strs.end());   
        
        int f = 0, l = strs.size() - 1;

        for(int i = 0; i < strs[f].size(); i++) {
            if(strs[l].size() > i && strs[f][i] == strs[l][i]) {
                res += strs[f][i];
            } else {
                break;
            }
        }

        return res;
    }
};