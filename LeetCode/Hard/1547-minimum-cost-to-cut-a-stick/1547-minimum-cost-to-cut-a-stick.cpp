class Solution {
public:
    // Original  Process: (partition dp)
    // The state rec(i, j) means the cost for a stick from position i to position j.
    // To solve for rec(i, j), I'll try every available cut from the original 'cuts' array.
    // If a cut is valid (between i and j), I'll calculate the cost and recurse on the
    // new stick positions. This is inefficient because I rescan all cuts every time.

    // --- Original Recurrence ---
    // rec(i, j): --> min cost for stick from physical position 'i' to 'j'

        // int costOfThisCut = j - i;
        // int mini = infinity;

        // For every cut 'c' in the original 'cuts' array:
        //     if (i < c && c < j)
        //         int ans = costOfThisCut + rec(i, c) + rec(c, j);
        //         mini = min(mini, ans);

        // return mini;

    // Optimal Thought Process: (partition dp, like mcm)
    // Instead of positions, let the state represent an interval between cuts (the actual points where the cuts are).
    // First, I'll create a new sorted array 'c' (c here is cuts array) containing 0, n, and all the original cuts.
    // Now, rec(i, j) means the cost for the stick segment between c[i] and c[j].
    // 'i' and 'j' are now INDICES of array 'c'. This way, the loop for 'k' only
    // needs to go from i+1 to j-1 to test all valid cuts within this segment.

    // --- Refined Recurrence --- 
    // First, create a sorted array 'c' = {0} U cuts U {n}
    // rec(i, j): --> min cost for stick segment from c[i] to c[j]

        // Base Case: No cuts exist between c[i] and c[j].
        // if (j - i <= 1) return 0;

        // The cost of the first cut is the length of the current segment.
        // int costOfThisCut = c[j] - c[i];
        // int min_cost = infinity;

        // Try every valid cut 'k' between indices i and j.
        // k is the INDEX of the cut in array 'c'.
        // for k from i + 1 to j - 1:
        //     int ans = costOfThisCut + rec(i, k) + rec(k, j);
        //     min_cost = min(min_cost, ans);

        // return min_cost;

    // Tabulation 
    int minCost(int n, vector<int>& cuts) {
       cuts.push_back(0);
       cuts.push_back(n);
       sort(cuts.begin(), cuts.end());

       int m = cuts.size();
       vector<vector<int>> dp(m, vector<int>(m, 1e9));

       for(int i = 0; i < m - 1; i++)  dp[i][i + 1] = 0; // base case

       for(int i = m - 1; i >= 0; i--) {
          for(int j = i + 1; j < m; j++) {
            int costOfThisCut = cuts[j] - cuts[i];

            for(int k = i + 1; k < j; k++) {
                int curr = costOfThisCut + dp[i][k] + dp[k][j];
                dp[i][j] = min(dp[i][j], curr); 
            }
          }
       }

       return dp[0][m - 1];
    }
};