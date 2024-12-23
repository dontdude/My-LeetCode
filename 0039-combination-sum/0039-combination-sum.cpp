class Solution {
public:
    void recursion(int i, vector<int>& cur, vector<vector<int>>& res, vector<int>& c, int target){
       if(target == 0) {
          res.push_back(cur);
          return;
       } 

       for(int j = i; j < c.size(); j++){
           if(c[j] <= target){
               cur.push_back(c[j]);
               recursion(j, cur, res, c, target - c[j]);
               cur.pop_back();
           }
       } 
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        recursion(0, cur, res, candidates, target);
        return res;
    }
};