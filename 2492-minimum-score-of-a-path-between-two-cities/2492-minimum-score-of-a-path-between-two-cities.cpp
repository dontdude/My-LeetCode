class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<int> vis(n+1, 0);
        vector<vector<pair<int, int>>> graph(n+1);

        for(auto road : roads){
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        queue<int> q;
        q.push(1);
        int res = INT_MAX;

        while(!q.empty()){
            auto u = q.front();   q.pop();

            for(auto v : graph[u]){
                res = min(res, v.second);     // Notice that if the graph is connected, you can always use any edge of the graph in your path.
                
                if(!vis[v.first]) {
                    q.push(v.first);
                    vis[v.first] = 1;
                }
            }
        }

        return res;
    }
};