class Solution {
    int n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isSafe(int x, int y) {
        return (x >= 0 && x < n) && (y >= 0 && y < n);
    }

    void prepareManhattanGrid(vector<vector<int>>& grid, vector<vector<int>>& manhattanGrid) {
        queue<pair<int, int>> q;  // why q, because the progression of distance is always linearly increased as every new cell will increment by 1 distance

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    manhattanGrid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();

            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(isSafe(x, y) && manhattanGrid[x][y] > manhattanGrid[i][j] + 1) {
                    manhattanGrid[x][y] = manhattanGrid[i][j] + 1;
                    q.push({x, y});
                }
            }
        }
    }

    int maxHeapDijkstra(vector<vector<int>>& manhattanGrid) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<int>> vis(n, vector<int>(n, 0));

        maxHeap.push({manhattanGrid[0][0], {0, 0}});
        vis[0][0] = 1;

        while(!maxHeap.empty()) {
            int dist = maxHeap.top().first;
            int i = maxHeap.top().second.first;
            int j = maxHeap.top().second.second;
            maxHeap.pop();

            if(i == n - 1 && j == n - 1) {
                return dist;
            }
            
            for(int k = 0; k < 4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if(isSafe(x, y) && vis[x][y] == 0) {
                    vis[x][y] = 1;
                    int maxSafeCurr = min(dist, manhattanGrid[x][y]);
                    maxHeap.push({maxSafeCurr,  {x, y}});
                }
            }
        }

        return 0;
    }
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        n = grid.size();
        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1)  return 0;

        vector<vector<int>> manhattanGrid(n, vector<int>(n, n + n));

        prepareManhattanGrid(grid, manhattanGrid);

        return maxHeapDijkstra(manhattanGrid);
    }
};