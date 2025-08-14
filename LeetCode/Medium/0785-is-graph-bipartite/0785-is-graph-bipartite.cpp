class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, 0);

        for(int i = 0; i < n; i++){
            if(colors[i] == 0 && !validColors(i, 1, colors, graph))   return false;
        }

        return true;
    }

    bool validColors(int u, int color, vector<int>& colors, vector<vector<int>>& graph){
        if(colors[u] == -color)  return false;
        if(colors[u] == color)   return true;    // parent node is colored, so all it's adjacent node would be colored too, no need to color, it's adjacent
        colors[u] = color;

        for(int v : graph[u]){
            if(!validColors(v, -color, colors, graph))  return false;
        }

        return true;
    }
};