class Solution {
public:
    bool dfsTopoSort(int node, vector<int>& vis, vector<int>& res, vector<vector<int>>& graph) {
        if (vis[node] == 1) return true;
        if (vis[node] == 2) return false;

        vis[node] = 1;
        for (int nebr : graph[node]) {
            if (dfsTopoSort(nebr, vis, res, graph))  return true;
        }
        res.push_back(node);
        vis[node] = 2;

        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // code here
        vector<vector<int>> graph(numCourses);
        vector<int> vis(numCourses, 0);

        for (auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> res;
        for (int i = 0; i < numCourses; i++) {
            if (dfsTopoSort(i, vis, res, graph)) return vector<int>();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};