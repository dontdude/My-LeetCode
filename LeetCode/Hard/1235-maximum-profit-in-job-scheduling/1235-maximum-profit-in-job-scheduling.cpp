class Solution {
public:
    // Recurrence relation: (sort the items based on start index, so we only need to track end index now)
    // rec(i, j)   // i = index (0 -> n),  j = end_index (1 -> endTime.back())
    //     if i >= n  return 0
    
    //     int not_pick = rec(i + 1, j)

    //     int pick
    //     if start[i] >= j: 
    //         pick = pofit[i] + rec(i + 1, end[i])

    //     return max(pick, not_pick)


    // Recurrence relation: (optimized, 1d dp)  { Prerequisite: Jobs are combined and sorted by startTime. }
    // solve(i)  // i = index in the sorted jobs array (0 -> n)
    //          
    //     if (i >= n) return 0; // Base case: no more jobs to consider.

    //     // --- Choice 1: Don't pick job i ---
    //     // Simply move to the next job and see the best we can do from there.

    //     int not_pick = solve(i + 1);

    //     // --- Choice 2: Pick job i ---
    //     // We take the profit of job i.
    //     // Then, we find the earliest next job that we can take (one that doesn't overlap).

    //     Let next_i = the index of the first job where jobs[next_i].start >= jobs[i].end    // (This is found using binary search).

    //     int pick = jobs[i].profit + solve(next_i);

    //     return max(pick, not_pick);

    // Tabulation
    struct Job {
        int start;
        int end;
        int profit;
    };

    int equalOrGreater(vector<Job>& jobs, int target, int l, int n) {
        int r = n - 1;
        int res = n;    // if no found, return n

        while(l <= r) {
            int mid = (r - l) / 2 + l;

            if(jobs[mid].start >= target) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return res;
    }

    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        // Prerequisite
        int n = startTime.size();
        vector<Job> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {startTime[i], endTime[i], profit[i]};
        }

        sort(jobs.begin(), jobs.end(), [](const Job& a, const Job& b) {
            return a.start < b.start;   // sorted based on start time
        });

        // core logic
        vector<int> dp(n + 1, INT_MIN);

        dp[n] = 0;  // base case

        for(int i = n - 1; i >= 0; i--) {
            // not pick case
            int not_pick = dp[i + 1]; 

            
            // pick case
            int pick = INT_MIN;

            int next_i = equalOrGreater(jobs, jobs[i].end, i + 1, n);  // binary search to find the next closest start.. that is greater than current end. 

            if(next_i <= n) {
                pick = jobs[i].profit + dp[next_i];
            }

            dp[i] = max(pick, not_pick);
        }

        return dp[0];
    }
};