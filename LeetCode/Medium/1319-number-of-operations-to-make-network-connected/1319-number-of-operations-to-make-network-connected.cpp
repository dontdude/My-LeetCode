class Solution {
    void dfs(int u, vector<char>& vis, vector<vector<int>>& graph) {
        vis[u] = 1;

        for(int v : graph[u]) {
            if(vis[v] == 0) {
                dfs(v, vis, graph);
            } 
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<vector<int>> graph(n, vector<int>());

        for(const auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        vector<char> vis(n, 0);
        
        int connectedComponents = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                connectedComponents++;
                dfs(i, vis, graph);
            }
        }

        return connectedComponents - 1;
    }
};