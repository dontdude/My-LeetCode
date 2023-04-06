class Solution {
public:
    int n, m;
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    int closedIsland(vector<vector<int>>& grid) {
        int res = 0;
        n = grid.size(), m = grid[0].size();
        
        for(int i = 1; i < n-1; i++){
            for(int j = 1; j < m-1; j++){
                if(grid[i][j] == 0 && bfs(i, j, grid))  res++;
            }
        }
        return res;
    }

    bool bfs(int i, int j, vector<vector<int>>& grid){
        bool res = true;
        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = -1;             
        
        while(!q.empty()){
            auto cell = q.front();   q.pop();
            
            for(int k = 0; k < 4; k++){
                int x = cell.first + dx[k];
                int y = cell.second + dy[k];

                if(x < 0 || y < 0 || x == n || y == m)   res = false;  
                else if(grid[x][y] == 0){  
                    grid[x][y] = -1;
                    q.push({x, y});
                }
            }
        }
        return res;
    }
};