class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isSafe(int x, int y, int m, int n) {
        return (x >= 0 && x < m) && (y >= 0 && y < n);
    }
    void bfs(int i, int j, vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = '2';

        while(!q.empty()) {
            pair<int, int> cell = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int x = dx[k] + cell.first;
                int y = dy[k] + cell.second;

                if(isSafe(x, y, m, n) && grid[x][y] == '1') {
                    grid[x][y] = '2';
                    q.push({x, y});
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] == '1') {
                    bfs(i, j, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};