class Solution {
    bool dfsColor(int u, int color, vector<int>& colorVis, vector<vector<int>>& graph) {
        colorVis[u] = color;

        for(int v : graph[u]) {
            if(colorVis[v] == 0) {
                if(dfsColor(v, -color, colorVis, graph) == false)  return false;
            } else if(colorVis[v] == color) {
                return false;
            }
        }

        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorVis(n, 0);

        for(int i = 0; i < n; i++) {
            if(colorVis[i] == 0) {
                if(dfsColor(i, 1, colorVis, graph) == false)  return false; 
            }   
        }

        return true;
    }
};