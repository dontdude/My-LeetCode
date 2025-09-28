class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int n = s.size();
        vector<bool> dp(n, false);    // dp[i] = true if word ending at i, is present 

        for(int i = 0; i < n; i++){
            for(int j = i; j >= -1; j--){            // j = -1, than considering word staring from index 0 and ending at index i
                if(j == -1 || dp[j]){

                    string curword = s.substr(j + 1, i - j);

                    for(string word : wordDict) {
                        if(curword == word){
                            dp[i] = true;
                            break;
                        }
                    }

                    if(dp[i])  break;
                }
            }
        }

        return dp[n-1];
    }
};