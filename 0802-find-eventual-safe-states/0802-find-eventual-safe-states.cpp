class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res, vis(n, 0);   
        // vis[u] =  0 : unknown, 1 : safe, -1 : unsafe
        
        if(n == 0) return res;

        for(int i = 0; i < n; i++){
            if(dfs(i, vis, graph))  res.push_back(i);
        }

        return res;
    }

    bool dfs(int u, vector<int>& vis, vector<vector<int>>& graph){
        if(vis[u])   return vis[u] == 1;

        vis[u] = -1;
        for(int v : graph[u]){
            if(!dfs(v, vis, graph))  return false;
        }
        vis[u] = 1;

        return true;
    }
};