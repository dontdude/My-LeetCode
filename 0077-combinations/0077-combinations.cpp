class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> combination;
        generateCombinations(n, k, 1, combination);
        return res;
    }
    void generateCombinations(int n, int k, int x, vector<int>& combination){
        int nk = combination.size();
        if(nk == k) {
            res.push_back(combination);
            return;
        }

        for(int i = x; i <= n; i++){
            combination.push_back(i);
            generateCombinations(n, k, i + 1, combination);
            combination.pop_back();
        }
    }
};