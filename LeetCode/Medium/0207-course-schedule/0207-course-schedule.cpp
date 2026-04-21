class Solution {
    bool topoSort(vector<vector<int>>& graph, vector<int>& indegree, int n) {
        queue<int> q;
        int processed = 0;
        
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
                indegree[i]--;
                processed++;
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nebr: graph[node]) {
                indegree[nebr]--;
                if(indegree[nebr] == 0) {  cout<<node<<" "<<nebr<<endl;
                    q.push(nebr);
                    indegree[nebr]--;
                    processed++;
                }
            }
        }

        return processed == n;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);

        for(vector<int> preq : prerequisites) {
            graph[preq[1]].push_back(preq[0]);
            indegree[preq[0]]++;
        }

        return topoSort(graph, indegree, numCourses);
    }
};