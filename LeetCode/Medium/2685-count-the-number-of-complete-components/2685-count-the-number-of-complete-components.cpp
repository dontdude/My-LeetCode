class Solution {
    void dfs(int u, vector<int>& vis, vector<vector<int>>& graph, unordered_set<int>& vertices) {
        vis[u] = 1;
        vertices.insert(u);

        for(const int& v : graph[u]) {
            if(vis[v] == 0) {
                dfs(v, vis, graph, vertices);
            }
        }
    }

    bool isConnectedComponent(unordered_set<int>& vertices, vector<vector<int>>& graph) {
        for(const int& v : vertices) {
            if(graph[v].size() != vertices.size() - 1) return false;

            for(const int& nebr : graph[v]) {
                if(vertices.find(nebr) == vertices.end())  return false;
            }
        }

        return true;
    }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);

        for(const auto& edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int connectedComponents = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                unordered_set<int> vertices;
                dfs(i, vis, graph, vertices);

                if(isConnectedComponent(vertices, graph))  connectedComponents++;
            }
        }

        return connectedComponents;
    }
};