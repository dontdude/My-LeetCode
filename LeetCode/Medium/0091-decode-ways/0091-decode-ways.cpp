class Solution {
    bool isValidPair(const char& first, const char& second) {
        return (first == '1') || (first == '2' && second < '7');
    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        
        if(s[0] == '0')  return 0;
        else dp[0] = 1;

        for(int i = 1; i < n; i++) {
            if(s[i] != '0')  dp[i] = dp[i - 1];

            if(isValidPair(s[i - 1], s[i])) {
                dp[i] += (i > 1) ? dp[i - 2] : 1;   // 1 way of getting even empty 
            }
        }

        return dp[n - 1];
    }
};