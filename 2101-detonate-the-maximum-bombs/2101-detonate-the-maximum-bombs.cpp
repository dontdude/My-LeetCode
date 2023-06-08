class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j)  continue;

                long long distSq = pow(bombs[i][0] - bombs[j][0], 2) + pow(bombs[i][1] - bombs[j][1], 2);
                if((long long)bombs[i][2] * bombs[i][2] >= distSq)  adj[i].emplace_back(j);
            }
        }

        int res = 0;
        // Todo : whether dp on dfs can be applied, the problem faced right now is, when one of the branch visits a dp, the other branch can't visit it again due to vis array, even if this branch could have detonated that bomb. (Refer previous submission)  
        for(int i = 0; i < n; i++){
            vector<bool> vis(n, false);
            res = max(res, dfs(i, vis, adj));  
        }

        return res;
    }

    int dfs(int u, vector<bool>& vis, vector<vector<int>>& adj){
        vis[u] = true;
        int curr = 1;

        for(auto v : adj[u]){
            if(!vis[v])  curr += dfs(v, vis, adj);
        }

        return curr;
    }
};