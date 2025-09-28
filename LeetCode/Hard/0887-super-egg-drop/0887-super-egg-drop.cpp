class Solution {
public:
    // --- Egg Dropping Puzzle: Quick Logic ---
    // * 'k' (Eggs) as a Resource:
    //   - 'k' determines the optimal strategy. More eggs allow for riskier, faster approaches.
    //   - k=1: The only safe strategy is a slow, linear scan (floors 1, 2, 3...). Max moves: n.
    //   - k>1: Allows you to skip floors, as you have a backup egg if the first one breaks.

    // * Core DP Recurrence:
    //   - A drop from floor 'x' creates two subproblems. We must minimize the worst outcome:
    //     1. Egg Breaks \U0001f4a5: Solve for (k-1 eggs, x-1 floors below).
    //     2. Egg Survives ✅: Solve for (k eggs, n-x floors above).

    // * Note 1: Moves are sequential. One drop is one move. The outcome informs the next move.
    // * Note 2: It doesn't depend on which floors they are (e.g., floors 1-10 vs. 101-110), but only on how many floors are in that range.

    // Recurrence relation:
    // rec(i, e)   // i = number of floors, e = eggs (i = n -> 1, j = k -> 1)
    //     if (i <= 1) return i;  // If 0/1 floors, takes 0/1 moves.
    //     if (e == 1) return i;  // If 1 egg, must do linear scan.

    //     int min_moves = INT_MAX;

    //     // Try dropping from every floor j from 1 to i
    //     for (int j = 1; j <= i; j++) {   // linearly searching for optimal floor
    //         int worst_case_for_this_drop = 1 + max(rec(j - 1, e - 1), rec(i - j, e));
    //         mini = min(min_moves , worst_case_for_this_drop);
    //     }
    //     return min_moves;


    // Tabulation (With binary search, instead of linearly dropping from every floor from 1 to i)
    int superEggDrop(int k, int n) {
        // dp[i][j] = min moves for 'i' floors and 'j' eggs.
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));

        // Base case: With 1 egg, we need 'i' moves for 'i' floors (linear scan).
        for (int i = 1; i <= n; i++) {
            dp[i][1] = i;
        }

        // Base case: With any eggs, 1 floor needs 1 move.
        for (int j = 1; j <= k; j++) {
            dp[1][j] = 1;
        }

        for (int i = 2; i <= n; i++) {
            for (int j = 2; j <= k; j++) {
                
                // Binary search for the optimal floor to drop from.
                int low = 1, high = i;

                while (low <= high) {
                    int mid_floor = low + (high - low) / 2;
                    
                    int breaks_case = dp[mid_floor - 1][j - 1]; 
                    int survives_case = dp[i - mid_floor][j];   

                    int worst_case = 1 + max(breaks_case, survives_case);
                    dp[i][j] = min(dp[i][j], worst_case);

                    // Move towards the current worst-case (the larger subproblem) to balance the outcomes.
                    if (breaks_case < survives_case) {  // surviver worst case is too big, trying to reduce it
                        low = mid_floor + 1;
                    } else {
                        high = mid_floor - 1;
                    }
                }
            }
        }

        return dp[n][k];
    }
};