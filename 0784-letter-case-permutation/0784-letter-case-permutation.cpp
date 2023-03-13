class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> res;
        permute(0, s, res);
        return res;
    }
    void permute(int x, string s, vector<string>& res){

        if(x == s.size()){
            res.push_back(s);
            return;
        }

        permute(x + 1, s, res);    
        
        if(isalpha(s[x])){
            if(s[x] >= 'a')  s[x] = (char)(s[x] - 32);     // converting s[x] to uppercase 
            else if(s[x] <= 'Z')  s[x] = (char)(s[x] + 32);     // converting s[x] to uppercase 
            
            permute(x + 1, s, res);
        }
    }
};