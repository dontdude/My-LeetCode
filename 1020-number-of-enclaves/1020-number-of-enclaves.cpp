class Solution {
public:
    int m, n;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

    int numEnclaves(vector<vector<int>>& grid) {
        int res = 0;
        m = grid.size(), n = grid[0].size();
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1) {
                    int cells = 0; 
                    bool isBoundaryCell = false;
                    dfs(i, j, cells, isBoundaryCell, grid);
                    if(!isBoundaryCell)  res += cells;
                }
            }
        }
        return res;
    }

    void dfs(int i, int j, int& cells, bool& isBoundaryCell, vector<vector<int>>& grid){
        grid[i][j] = -1;
        cells++;

        for(int k = 0; k < 4; k++){
            int x = i + dx[k], y = j + dy[k];

            if(x < 0 || y < 0 || x >= m || y >= n)  isBoundaryCell = true;
            else if(grid[x][y] == 1)    dfs(x, y, cells, isBoundaryCell, grid);
        }
    }
};