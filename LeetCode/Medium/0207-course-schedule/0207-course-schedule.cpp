class Solution {
public:
    // BFS Solution (Kahn's algorthm)
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<vector<int>> graph(numCourses);
    //     vector<int> in_degree(numCourses, 0);

    //     for (auto prereq : prerequisites) {
    //         graph[prereq[1]].push_back(prereq[0]);
    //         in_degree[prereq[0]]++;
    //     }

    //     int doableCourses = 0;
    //     queue<int> q;

    //     for (int i = 0; i < numCourses; i++) {
    //         if (in_degree[i] == 0) {
    //             q.push(i);
    //             in_degree[i]--;
    //             doableCourses++;
    //         }
    //     }

    //     while (!q.empty()) {
    //         int node = q.front();
    //         q.pop();

    //         for(int nebr: graph[node]) {
    //             in_degree[nebr]--;
    //             if(in_degree[nebr] == 0) {
    //                 q.push(nebr);
    //                 doableCourses++;
    //             }
    //         }
    //     }

    //     return numCourses == doableCourses;
    // }

    // DFS
    bool hasCycle(int node, vector<vector<int>>& graph, vector<int>& vis) {
        vis[node] = 1;
        for(int nebr: graph[node]) {
            if(vis[nebr] == 0) {
                if(hasCycle(nebr, graph, vis))  return true;
            } else if(vis[nebr] == 1) {  // reaches any node, in current connected componnets
                return true;
            } // else vis[nebr] == 2, means, it is already visited in another connection and doen't have any cycle
        }
        vis[node] = 2;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> vis(numCourses, 0);
        
        for(auto prereq: prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
        }

        for(int i = 0; i < numCourses; i++) {
            if(vis[i] == 0) {
                if(hasCycle(i, graph, vis)) {
                    return false;
                }
            }
        }

        return true;
    }
};