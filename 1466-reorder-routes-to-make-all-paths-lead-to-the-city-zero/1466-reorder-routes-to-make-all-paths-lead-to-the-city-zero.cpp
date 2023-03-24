class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> vis(n, false);
        vector<vector<pair<int, bool>>> graph(n);
        
        for(auto edge : connections){
            graph[edge[1]].push_back({edge[0], true});
            graph[edge[0]].push_back({edge[1], false});
        }

        queue<int> q;
        q.push(0);
        vis[0] = true;
        int res = 0;

        while(!q.empty()){
           int u = q.front();   q.pop();
           for(auto v : graph[u]){
               if(vis[v.first])  continue;
               if(!v.second)  res++;
               q.push(v.first);
               vis[v.first] = true;
           }
        }

        return res;
    }
};