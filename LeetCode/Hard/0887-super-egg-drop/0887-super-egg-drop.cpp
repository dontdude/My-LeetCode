class Solution {
public:
    // int superEggDrop(int k, int n) {
    //     vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));  // moves * eggs metrics. Where moves in worst case (eggs = 1) is equal to number of floor

    //     int moves = 0;

    //     while(dp[moves][k] < n) {
    //         moves++;
    //         for(int eggs = 1; eggs <= k; eggs++) {
    //             int floors_possible_with_given_moves_and_broken_egg = dp[moves - 1][eggs - 1];
    //             int floors_possible_with_given_moves_and_unbroken_egg = dp[moves - 1][eggs];

    //             int current_floor = 1;

    //             dp[moves][eggs] = current_floor 
    //                                 + floors_possible_with_given_moves_and_broken_egg 
    //                                 + floors_possible_with_given_moves_and_unbroken_egg;
    //         }
    //     }

    //     return moves;
    // }

    // 1D approach
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1, 0);  

        int moves = 0;

        while(dp[k] < n) {
            moves++;
            for(int eggs = k; eggs >= 1; eggs--) {
                dp[eggs] += 1 + dp[eggs - 1];
            }
        }

        return moves;
    }
};