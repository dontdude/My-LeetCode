class Solution {
public:    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto edge : edges){
            graph[edge[0]].emplace_back(edge[1]);
        }
        
        vector<int> vis(n, -1), res;
        for(int i = 0; i < n; i++){
            if(vis[i] == -1) {
                dfs(i, i, vis, graph);  
            }
        }
        
        unordered_set<int> st(vis.begin(), vis.end());
        for(auto e : st)  res.emplace_back(e);

        return res;
    }

    void dfs(int i, int u, vector<int>& vis, vector<vector<int>>& graph){
        vis[u] = i;
        for(auto v : graph[u]){
            if(vis[v] != i)  dfs(i, v, vis, graph);
        }
    }
};