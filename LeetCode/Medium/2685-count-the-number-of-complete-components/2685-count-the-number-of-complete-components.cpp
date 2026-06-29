class Solution {
    void dfs(int u, vector<int>& vis, vector<vector<int>>& graph, int& nodeCount, int& degree) {
        vis[u] = 1;
        nodeCount++;

        degree += graph[u].size();

        for(const int& v : graph[u]) {
            if(vis[v] == 0) {
                dfs(v, vis, graph, nodeCount, degree);
            }
        }
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
                int nodeCount = 0;
                int degree = 0;

                dfs(i, vis, graph, nodeCount, degree);

                if(degree == (nodeCount * (nodeCount - 1)))  connectedComponents++;
            }
        }

        return connectedComponents;
    }
};