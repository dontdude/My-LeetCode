class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isSafe(int x, int y, int m, int n) {
        return ((x >= 0 && x < m) && (y >= 0 && y < n));
    }
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        if (m == 1 && n == 1) return grid[0][0];

        vector<vector<vector<vector<long long>>>> dp(m, vector<vector<vector<long long>>>(n, vector<vector<long long>>(4, vector<long long>(k + 1, INT_MAX))));  // 4d dp {m, n, direction, k}

        priority_queue<pair<long long, vector<int>>> pq;  // {dist, {i, j, dir, k}}
        
        for(int d = 0; d < 4; d++) {
            int x = dx[d];
            int y = dy[d];

            if(isSafe(x, y, m, n)) {
                dp[x][y][d][k] = grid[0][0] + grid[x][y];
                pq.push({-dp[x][y][d][k], {x, y, d, k}});
            }
        }

        while(!pq.empty()) {
            long long d = -pq.top().first;
            int i = pq.top().second[0];
            int j = pq.top().second[1];
            int dir = pq.top().second[2];
            int currK = pq.top().second[3];
            pq.pop();

            if(i == m - 1 && j == n - 1)  return d;
            if(dp[i][j][dir][currK] < d)  continue;

            for(int ndir = 0; ndir < 4; ndir++) {
                int x = i + dx[ndir];
                int y = j + dy[ndir];

                if(!isSafe(x, y, m, n)) continue;

                int nebrK = dir == ndir ? currK : currK - 1;
                if(nebrK < 0) continue;

                if(d != INT_MAX && dp[x][y][ndir][nebrK] > d + grid[x][y]) {
                    dp[x][y][ndir][nebrK] = d + grid[x][y];
                    pq.push({-dp[x][y][ndir][nebrK], {x, y, ndir, nebrK}});
                }
            } 
        }

        return -1;
    }
};