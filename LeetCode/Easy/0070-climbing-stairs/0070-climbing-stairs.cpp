class Solution {
    // rec(i)   // i = n - > i = 1
    //     if(i == 0)  return 1

    //     ways += rec(i - 1);
    //     if(i > 1) ways += rec(i - 2)

    //     return ways
public:
    int climbStairs(int n) {
        if(n <= 1)  return 1;

        int step1 = 1;
        int step2 = 0;

        for(int i = 1; i <= n; i++) {
            int ways = step1;
            if(i > 1)  ways += step2;

            step2 = step1;
            step1 = ways;
        }

        return step1;
    }
};