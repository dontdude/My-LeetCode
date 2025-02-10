class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size(), totalFresh = 0;
        queue<pair<int, int>> q;
        
        for(int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                } else if(grid[i][j] == 1){
                    totalFresh++;
                }
            }
        }

        int minute = -1;
        while(!q.empty()) {
            minute++;
            int levelSize = q.size();

            while(levelSize--) {
                auto rotten = q.front();   q.pop();
                
                for(int k = 0; k < 4; k++) {
                    int x = rotten.first + dx[k];
                    int y = rotten.second + dy[k];

                    if(((x < m && x >= 0) && (y < n && y >= 0)) && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        totalFresh--;
                        q.push({x, y});
                    }
                }
            }
        }

        return totalFresh == 0 ? (minute == -1 ? 0 : minute) : -1;
    }
};