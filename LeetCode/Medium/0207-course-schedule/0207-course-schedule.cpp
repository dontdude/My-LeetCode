class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> in_degree(numCourses, 0);

        for (auto prereq : prerequisites) {
            graph[prereq[1]].push_back(prereq[0]);
            in_degree[prereq[0]]++;
        }

        int doableCourses = 0;
        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            if (in_degree[i] == 0) {
                q.push(i);
                in_degree[i]--;
                doableCourses++;
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for(int nebr: graph[node]) {
                in_degree[nebr]--;
                if(in_degree[nebr] == 0) {
                    q.push(nebr);
                    doableCourses++;
                }
            }
        }

        return numCourses == doableCourses;
    }
};