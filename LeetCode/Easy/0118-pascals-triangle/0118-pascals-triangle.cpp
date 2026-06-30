class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for(int i = 1; i < n; i++) {
            vector<int> curRow;
            curRow.push_back(1);

            for(int j = 1; j < res[i - 1].size(); j++) {
                curRow.push_back(res[i - 1][j] + res[i - 1][j - 1]);
            }

            curRow.push_back(1);
            res.push_back(curRow);
        }

        return res;
    }
};