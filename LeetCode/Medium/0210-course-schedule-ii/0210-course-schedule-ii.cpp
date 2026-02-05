class Solution {
    bool topoSort(int n, vector<int>& inDegree, vector<int>& order, vector<vector<int>>& graph) {
        queue<int> q;
        int doable = 0;

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
                inDegree[i]--;
                order.push_back(i);
                doable++;
            }
        }

        while(q.empty() == false) {
            int u = q.front();
            q.pop();

            for(int v : graph[u]) {
                inDegree[v]--;
                if(inDegree[v] == 0) {
                    q.push(v);
                    order.push_back(v);
                    doable++;
                }
            }
        }

        return doable == n;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for(vector<int> pre: prerequisites) {
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        
        vector<int> order;
        bool isCoursesDoable = topoSort(numCourses, inDegree, order, graph);
        return isCoursesDoable ? order : vector<int>();
    }
};