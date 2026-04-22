class Solution {
    int m, n;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool isSafe(int x, int y) {
        return (x >= 0 && x < m) && (y >= 0 && y < n);
    }

    void dfs(int i, int j, vector<vector<bool>>& vis, vector<vector<int>>& h) {
        if(vis[i][j])  return;

        vis[i][j] = true;

        for(int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if(isSafe(x, y) && !vis[x][y] && h[x][y] >= h[i][j]) {
                dfs(x, y, vis, h);
            }
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        for(int i = 0; i < m; i++)  dfs(i, 0, pacific, heights);
        for(int j = 0; j < n; j++)  dfs(0, j, pacific, heights);

        for(int i = 0; i < m; i++)  dfs(i, n - 1, atlantic, heights);
        for(int j = 0; j < n; j++)  dfs(m - 1, j, atlantic, heights);

        vector<vector<int>> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};