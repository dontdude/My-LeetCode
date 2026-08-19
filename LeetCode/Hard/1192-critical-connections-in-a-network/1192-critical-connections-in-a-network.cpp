class Solution {
    int timer;
    vector<vector<int>> bridges;

    void dfs(int u, int parent, vector<char>& vis, vector<int>& discoveryTime, vector<int>& lowestReachableDiscTime, vector<vector<int>>& graph) {
        discoveryTime[u] = lowestReachableDiscTime[u] = timer++;
        vis[u] = 1;

        for(const int& v : graph[u]) {
            if(vis[v] == 0) {
                dfs(v, u, vis, discoveryTime, lowestReachableDiscTime, graph);
                lowestReachableDiscTime[u] = min(lowestReachableDiscTime[u], lowestReachableDiscTime[v]);
            } else if(v != parent) {
                lowestReachableDiscTime[u] = min(lowestReachableDiscTime[u], discoveryTime[v]);
            }

            if(lowestReachableDiscTime[v] > discoveryTime[u]) {
                bridges.push_back({u, v});
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n, vector<int>());
        for(const auto& connection : connections) {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        vector<int> discoveryTime(n), lowestReachableDiscTime(n);
        vector<char> vis(n, 0);

        timer = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                dfs(i, -1, vis, discoveryTime, lowestReachableDiscTime, graph);
            }
        }

        return bridges;
    }
};