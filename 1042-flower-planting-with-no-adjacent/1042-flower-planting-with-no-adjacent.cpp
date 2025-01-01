class Solution {
public:
    bool isFlowerSafe(int flower, int u, vector<int>& allocatedFlowers, vector<vector<int>>& graph) {
        for(auto v : graph[u]) {
           if(allocatedFlowers[v - 1] == flower) {
            return false;
           }
        }
        return true;
    }
    bool solve(int u, int n, vector<int>& allocatedFlowers, vector<vector<int>>& graph) {
        if(u > n) {
            return true;
        }

        for(int flower = 1; flower <= 4; flower++) {
            if(isFlowerSafe(flower, u, allocatedFlowers, graph)) {
                allocatedFlowers[u - 1] = flower;
                if(solve(u + 1, n, allocatedFlowers, graph)) return true;
                allocatedFlowers[u - 1] = 0;
            }
        }
        return false;
    }
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> allocatedFlowers(n, 0);
        vector<vector<int>> graph(n + 1);
        for(auto path: paths) {
            graph[path[0]].push_back(path[1]);
            graph[path[1]].push_back(path[0]);
        }
        solve(1, n, allocatedFlowers, graph);
        return allocatedFlowers;
    }
};