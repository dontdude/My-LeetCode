class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0, prv = grid[0].size(); 

        for(int i = 0; i < grid.size(); i++){
           int ind = upper_bound(grid[i].begin(), grid[i].begin() + prv, 0, greater<int>()) - grid[i].begin();
           res += grid[0].size() - ind;  
           prv = ind;
        }

        return res;
    }
};