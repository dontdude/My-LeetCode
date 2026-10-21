class Solution {
    // rec(i, v)  // i = n -> 1 & v = 0 -> 4
    //     if(i == 1 || v == 4)  return 1

    //     for(nextV = v -> 4) {
    //         ways += rec(i - 1, nextV)
    //     }

    //     return ways

    int solve(int i, int v) {
        if(i == 0)  return 1;

        int ways = 0;
        for(int nextv = v; nextv <= 4; nextv++) {
            ways += solve(i - 1, nextv);
        }

        return ways;
    }
public:
    int countVowelStrings(int n) {
        return solve(n, 0);
    }
};