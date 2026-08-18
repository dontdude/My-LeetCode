class Solution {
    void dfs(int u, vector<char>& vis, vector<vector<int>>& isConnected) {
        vis[u] = 1;

        for(int v = 0; v < isConnected[u].size(); v++) {
            if(isConnected[u][v] == 1 && vis[v] == 0) {
                dfs(v, vis, isConnected);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<char> vis(n, 0);

        int connectedComponent = 0;

        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                connectedComponent++;
                dfs(i, vis, isConnected);
            }
        }

        return connectedComponent;
    }
};