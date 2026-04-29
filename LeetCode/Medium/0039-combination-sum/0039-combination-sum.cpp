class Solution {
    void helper(int i, int target, vector<int>& combination, vector<vector<int>>& result, vector<int>& candidates) {
        if(target == 0) {
            result.push_back(combination);
            return;
        }

        if(i == candidates.size()) return;

        // take
        combination.push_back(candidates[i]);
        if(target >= candidates[i]) helper(i, target - candidates[i], combination, result, candidates);

        // not take
        combination.pop_back();
        helper(i + 1, target, combination, result, candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> combination;
        helper(0, target, combination, result, candidates);
        return result;
    }
};