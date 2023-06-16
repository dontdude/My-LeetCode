class Solution {
public:
    string removeDuplicates(string s) {
        string res = s;
        int j = 0;
        for(int i = 1; i < s.size(); i++){
            if(j != -1 && res[j] == s[i])   j--;

            else res[++j] = s[i];
        }
        res.resize(j+1); 

        return res;
    }
};