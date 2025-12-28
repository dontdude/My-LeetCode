class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid) {
        int minutes = -1;
        int m = grid.size(), n = grid[0].size();

        while(q.empty() == false) {
            int minuteLevel = q.size();
            minutes++;

            for(int level = 0; level < minuteLevel; level++) {
                pair<int, int> rotten = q.front();
                q.pop();

                for(int k = 0; k < 4; k++) {
                    int x = rotten.first + dx[k];
                    int y = rotten.second + dy[k];

                    if((x >= 0 && x < m) && (y >= 0 && y < n) && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }
        }

        return minutes == -1 ? 0 : minutes;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
         queue<pair<int, int>> q;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int minReq = bfs(q, grid);

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)  return -1;
            }
        }

        return minReq;
    }
};