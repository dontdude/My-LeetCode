class Solution {
    bool cleanUpBobPath(int i, int level, int& boblvl, int bob, vector<vector<int>>& adj, vector<int>& amount, vector<int>& vis) {
        vis[i] = 1;
        if(i == bob) {
            amount[i] = 0;
            boblvl = level;
            return true;
        }

        for(const int& child : adj[i]) {
            if(vis[child] == 1)  continue;
            bool bobFound = cleanUpBobPath(child, level + 1, boblvl, bob, adj, amount, vis);
            if(bobFound) {
                int midlvl = (boblvl + 1) / 2;
                if(midlvl < level)  amount[i] = 0;
                else if((boblvl & 1) && midlvl == level) amount[i] /= 2;
                return true;
            }
        }

        return false;
    }

    void findMaxPathToLeaf(int i, vector<vector<int>>& adj, vector<int>& amount, vector<int>& vis, int pathSum, int& result) {
        pathSum += amount[i];
        if(i != 0 && adj[i].size() == 1) result = max(result, pathSum);
        vis[i] = 1;
        
        for(const int& child : adj[i]) { 
            if(vis[child] == 0) {
                findMaxPathToLeaf(child, adj, amount, vis, pathSum, result);
            }
        }
    }
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n, vector<int>());

        for(const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        int boblvl = -1;
        cleanUpBobPath(0, 1, boblvl, bob, adj, amount, vis);

        int result = INT_MIN;
        fill(vis.begin(), vis.end(), 0);
        findMaxPathToLeaf(0, adj, amount, vis, 0, result);

        return result;
    }
};