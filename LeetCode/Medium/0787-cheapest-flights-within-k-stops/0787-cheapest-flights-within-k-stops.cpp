class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if(src == dst)  return 0;

        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<vector<int>> dp(n, vector<int>(k + 2, INT_MAX));  // dp is just dist in dijkstra
        priority_queue<pair<int, pair<int, int>>> pq;
        
        pq.push({0, {src, k + 1}});
        dp[src][k + 1] = 0;

        while(!pq.empty()) {
            int d = -pq.top().first;
            int u = pq.top().second.first;
            int currk = pq.top().second.second;
            pq.pop();

            if(dst == u)  return dp[u][currk];
            if(d > dp[u][currk])  continue;
            if(currk <= 0)  continue;

            for(const auto& [v, dist] : graph[u]) {
                int newCost =  d + dist;
                if(dp[v][currk - 1] > newCost) {
                    dp[v][currk - 1] = newCost;
                    pq.push({-newCost, {v, currk - 1}});
                }
            }
        }

        return -1;
    }
};