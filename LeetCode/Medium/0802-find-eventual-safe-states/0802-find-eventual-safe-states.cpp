class Solution {
    int n;
    vector<int> safeNodes;
    bool dfs(int u, vector<char>& vis, vector<vector<int>>& graph) {
        vis[u] = 1;

        for(int v : graph[u]) {
            if(vis[v] == 2)  continue;

            bool isNebrSafe = true;
            if(vis[v] == 0) {
                if(dfs(v, vis, graph) == false)  isNebrSafe == false;
            }

            if(isNebrSafe == false || vis[v] == 1 || vis[v] == 3) {
                vis[u] = 3;
            }
        }

        if(vis[u] == 3)  return false;

        safeNodes.push_back(u);
        vis[u] = 2;
        return true;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<char> vis(n, 0);

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, vis, graph);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};