class Solution {
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isValid(int x, int y, int ocean, vector<vector<int>>& grid) {
        return (x >= 0 && x < grid.size()) && (y >= 0 && y < grid[0].size()) && grid[x][y] != ocean && grid[x][y] != 0;
    }

    void dfs(int i, int j, int ocean, vector<vector<int>>& grid, vector<vector<int>>& heights) {
        if(grid[i][j] == INT_MAX) grid[i][j] = ocean;
        else if(grid[i][j] != ocean) grid[i][j] += ocean;

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(isValid(x, y, ocean, grid) && heights[i][j] <= heights[x][y]) {
                dfs(x, y, ocean, grid, heights);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> grid(m, vector<int>(n, INT_MAX));

        // Pacific edges
        int ocean = 1;
        // top row
        for(int i = 0; i < n; i++) {
            if(grid[0][i] != ocean) dfs(0, i, ocean, grid, heights);
        }

        // left col
        for(int i = 0; i < m; i++) {
            if(grid[i][0] != ocean) dfs(i, 0, ocean, grid, heights);
        }

        // Atlantic edges
        ocean = -1;
        // bottom row
        for(int i = 0; i < n; i++) {
            if(grid[m - 1][i] != ocean  && grid[m - 1][i] != 0) dfs(m - 1, i, ocean, grid, heights);
        }

        // right col
        for(int i = 0; i < m; i++) {
            if(grid[i][n - 1] != ocean && grid[i][n - 1] != 0) dfs(i, n - 1, ocean, grid, heights);
        }

        vector<vector<int>> result;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) result.push_back({i, j});
            }
        }

        return result;
    }
};