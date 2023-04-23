class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void bfs(int i, int j, vector<vector<bool>>& vis, vector<vector<bool>>& ocean, vector<vector<int>>& h){
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = true;
        ocean[i][j] = true;

        while(!q.empty()){
            auto cur = q.front();  q.pop();
            for(int k = 0; k < 4; k++){
                int x = dx[k] + cur.first, y = dy[k] + cur.second;

                if(x >= 0 && x < h.size() && y >= 0 && y < h[0].size() && h[cur.first][cur.second] <= h[x][y] && !vis[x][y]){
                    vis[x][y] = true;
                    ocean[x][y] = true;
                    q.push({x, y});
                }
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));
        vector<vector<bool>> pvis(m, vector<bool>(n, false)), avis(m, vector<bool>(n, false));
        
        
        for(int i = 0; i < m; i++){
            bfs(i, 0, pvis, pacific, heights);
            bfs(i, n-1, avis, atlantic, heights);
        }
        for(int j = 0; j < n; j++){
            bfs(0, j, pvis, pacific, heights);
            bfs(m-1, j, avis, atlantic, heights);
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacific[i][j] && atlantic[i][j])  res.push_back({i, j});
            } 
        }

        return res;
    }
};