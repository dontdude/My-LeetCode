class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);

        queue<pair<int, int>> q;  // {node, color}
        colors[0] = 1;
        q.push({0, 1});

        while(!q.empty()) {
           int node = q.front().first;
           int color = q.front().second;
           q.pop();

           for(int nebr : graph[node]) {
              if(colors[nebr] == 0) {
                colors[nebr] = -color;
                q.push({nebr, -color});
              } else if(colors[nebr] == color) {
                return false;
              }
           }
        }

        return true;
    }
};