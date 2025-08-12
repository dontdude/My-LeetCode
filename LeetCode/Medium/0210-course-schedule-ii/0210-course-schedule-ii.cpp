class Solution {
public:
    vector<int> kahnTopoSort(int V, vector<int>& in_degree, vector<vector<int>>& graph) {
        queue<int> q;
        vector<int> res;
        int doable = 0;
        
        for(int i = 0; i < V; i++) {
            if(in_degree[i] == 0) {
                q.push(i);
                doable++;
            }
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            in_degree[node]--;
            res.push_back(node);
            
            for(int nebr : graph[node]) {
                in_degree[nebr]--;
                if(in_degree[nebr] == 0) {
                    q.push(nebr);
                    doable++;
                }
            }
        }
        
        return doable == V ? res : vector<int>();
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // code here
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);
        
        for(auto edge : prerequisites) {
            graph[edge[1]].push_back(edge[0]);
            in_degree[edge[0]]++;
        }
        
        return kahnTopoSort(numCourses, in_degree, graph);
    }
};