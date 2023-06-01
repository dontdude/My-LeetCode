class Solution {
public:
    bool isvalid(int x, int y, int n){
        
        return (x >= 0 && x < n && y >= 0 && y < n);
    }
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
      
      int n = grid.size();
      if(grid[0][0] || grid[n-1][n-1])  return(-1);
      
      int steps = 0;
      queue<pair<int, int>> q;
      q.push({0, 0});
 
      while(!q.empty()) {
        
        steps++;
        int s = q.size();
          
         while(s--) {
          
            auto cell = q.front();    q.pop();
            int i = cell.first, j = cell.second;
             
            if(i == n-1 && j == n-1)  return(steps);

            for(int k = -1; k < 2; k++){
                for(int l = -1; l < 2; l++){
                    
                    int x = i + k, y = j + l;

                    if(isvalid(x, y, n) && !grid[x][y]){
                       q.push({x, y}); 
                       grid[x][y] = 1;
                    }  
                }
            } 
         }
      }
      return(-1);
    }
};