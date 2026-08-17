class Solution {
    int n;
    void dfs(int stone, int row, int col, vector<char>& vis, unordered_map<int, vector<pair<int, int>>>& rs, unordered_map<int, vector<pair<int, int>>>& cs) {
        vis[stone] = 1;

        for(const auto& cells : rs[row]) {
            if(vis[cells.first] == 1) continue;

            int rowStone = cells.first;
            int newCol = cells.second;
            dfs(rowStone, row, newCol, vis, rs, cs);
        }

        for(const auto& cells : cs[col]) {
            if(vis[cells.first] == 1)  continue;

            int colStone = cells.first;
            int newRow = cells.second;
            dfs(colStone, newRow, col, vis, rs, cs);
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        n = stones.size();
        vector<char> vis(n, 0);

        unordered_map<int, vector<pair<int, int>>> rowStones;
        unordered_map<int, vector<pair<int, int>>> colStones;

        for(int i = 0; i < n; i++) {
            rowStones[stones[i][0]].push_back({i, stones[i][1]});
            colStones[stones[i][1]].push_back({i, stones[i][0]});
        }

        int connectedComponents = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                connectedComponents++;
                dfs(i, stones[i][0], stones[i][1], vis, rowStones, colStones);
            }
        }

        return n - connectedComponents;
    }
};