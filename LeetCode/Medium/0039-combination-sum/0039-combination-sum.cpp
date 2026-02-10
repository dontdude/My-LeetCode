class Solution {
    void solve(int i, vector<int>& curr, vector<vector<int>>& res, int t, vector<int>& c) {
        if(t == 0) {
            res.push_back(curr);
            return;
        }
        
        if(t < 0 || i < 0) return;

        // take it
        curr.push_back(c[i]);
        solve(i, curr, res, t - c[i], c);

        // leave it
        curr.pop_back();
        solve(i - 1, curr, res, t, c);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> curr;
        solve(n - 1, curr, res, target, candidates);
        return res;
    }
};