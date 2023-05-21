class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    bool isValid(int x, int y, int n){
        return x >= 0 && x < n && y >= 0 && y < n;
    }
    void paintIsland(int i, int j, queue<pair<int, int>>& q, vector<vector<int>>& grid){
        grid[i][j] = 2;
        bool islandEdge = false;

        for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            
            if(!isValid(x, y, grid.size()))  continue;

            if(grid[x][y] == 0 && !islandEdge){
                q.push({i, j});        // only the edge cells of this painted island, are required to find shortest bridge
                islandEdge = true;
            }

            if(grid[x][y] == 1){
                paintIsland(x, y, q, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                   paintIsland(i, j, q, grid);
                   goto Painted;
                }
            }
        }

        Painted:
        while(!q.empty()){
            auto cell = q.front();   q.pop();
            int i = cell.first, j = cell.second; 

            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(!isValid(x, y, n))  continue;

                if(grid[x][y] == 1)  return grid[i][j] - 2;
                    
                if(grid[x][y] == 0){
                    grid[x][y] = grid[i][j] + 1;
                    q.push({x, y}); 
                }
            }
        }

        return 0; 
    }
};