class Solution {
    bool dfsTopoSort(int u, vector<int>& order, vector<int>& visited, vector<vector<int>>& graph) {
        visited[u] = 1;

        for(int v : graph[u]) {
            if(visited[v] == 0) {
                dfsTopoSort(v, order, visited, graph);
            } else if(visited[v] == 1) {
                return false;
            }
        }

        visited[u] = 2;
        order.push_back(u);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);

        for(vector<int> pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
        }

        vector<int> visited(numCourses, 0);
        vector<int> order;
        for(int i = 0; i < numCourses; i++) {
            if(visited[i] == 0) {
                if(dfsTopoSort(i, order, visited, graph) == false)  return vector<int>();
            }
        }

        reverse(order.begin(), order.end());
        return order;
    }
};