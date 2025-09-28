class Solution {
public:
    // Recurrence relation: (Partition DP)
    // rec(i, j): // returns a list of all palindrome partitions for s[i...j]

    //     all_partitions = an empty list

    //     // Case 1: The entire substring s[i...j] is a single palindrome
    //     if (isPalindrome(s, i, j)):
    //         all_partitions.add( { substring(s, i, j) } )

    //     // Case 2: Split the substring at 'k' and combine the results
    //     for (k from i to j-1):
    //         left_partitions = rec(i, k)
    //         right_partitions = rec(k+1, j)
            
    //         // Combine every partition from the left with every partition from the right
    //         for each l_part in left_partitions:
    //             for each r_part in right_partitions:
    //                 all_partitions.add( l_part + r_part ) // (e.g., ["a"] + ["a","b"] -> ["a","a","b"])

    //     return all_partitions


    // Recurrence relation (optimal 1d dp approach)
    // rec(i):  // where n = s.length
    //     // Base Case: Reached the end. Return a list with one empty partition as a success signal.
    //     if (i == n) return {{}}; 

    //     all_partitions = empty list

    //     for(int k = i -> n-1):
    //         string sub = s[i:k];
    //         if(isPalindrome(sub)) {
    //             // Get all partitions for the rest of the string.
    //             right_partitions = rec(k + 1);

    //             // Prepend the current palindrome 'sub' to each of the right-side partitions.
    //             for each r_part in right_partitions:
    //                 all_partitions.add( {sub} + r_part );
    //         }
    //     }

    //     return all_partitions;


    // Tabulation (using 1d dp)
    vector<vector<string>> partition(string s) {
         int n = s.length();
        
        // Pre-compute isPal[i][j] for O(1) palindrome checks.
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        preComputeIsPalindrome(isPal, s);

        // dp[i] stores all palindrome partitions for the suffix s[i...end].
        vector<vector<vector<string>>> dp(n + 1);

        dp[n].push_back({});  // base case

        for (int i = n - 1; i >= 0; i--) {
            for (int k = i; k < n; k++) {
                if (isPal[i][k]) {
                    string current_palindrome = s.substr(i, k - i + 1);
                    
                    // Prepend current palindrome to each partition found for the rest of the string.
                    for (auto right_partition : dp[k + 1]) {
                        vector<string> new_partition = {current_palindrome};
                        new_partition.insert(new_partition.end(), right_partition.begin(), right_partition.end());
                        dp[i].push_back(new_partition);
                    }
                }
            }
        }

        return dp[0];
    }

    void preComputeIsPalindrome(vector<vector<bool>>& isPal, string& s) {
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            // Odd length
            for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
                isPal[i - j][i + j] = true;
            // Even length
            for (int j = 0; i - j >= 0 && i + j + 1 < n && s[i - j] == s[i + j + 1]; ++j)
                isPal[i - j][i + j + 1] = true;
        }
    }
};