class Solution {
    // recurrren relation:
    // rec(i) : i = 0 -> n
    //     if i == n =>  return 1
    //     else if i > n => return 0

    //     if s[i] == 0 => return 0

    //     sum += rec(i + 1)
    //     if(num[i, i + 1] <= 26) sum += rec(i + 2)
public:
    int numDecodings(string s) {
        if(s[0] == 0)  return 0;

        int n = s.size();

        vector<int> dp(n + 1, 0);
        dp[n] = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0')  {
                dp[i] = 0;
                continue;
            }

            dp[i] += dp[i + 1];

            if(i < n - 1) {
                int dig = s[i] - '0';
                int num = dig * 10 + (s[i + 1] - '0');

                if(num <= 26) {
                    dp[i] += dp[i + 2];
                }
            }
        }

        return dp[0];
    }
};