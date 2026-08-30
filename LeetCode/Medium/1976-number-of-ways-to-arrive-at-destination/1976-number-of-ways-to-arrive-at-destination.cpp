class Solution {
    int mod = 1e9 + 7;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
        for(const auto& road : roads) {
            graph[road[0]].push_back({road[1], road[2]});
            graph[road[1]].push_back({road[0], road[2]});
        }

        vector<long long> dist(n, LLONG_MAX); 
        vector<int> ways(n, 0);
        priority_queue<pair<long long, int>> pq;

        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while(!pq.empty()) {
            int u = pq.top().second;
            long long d = -pq.top().first;
            pq.pop();

            if(d > dist[u]) continue;

            for(const auto& nebr : graph[u]) {
                int v = nebr.first;
                int time = nebr.second;

                if(dist[v] > d + time) {
                    dist[v] = d + time;
                    ways[v] = ways[u];
                    pq.push({-dist[v], v});
                } else if(dist[v] == d + time) {
                    ways[v] = (ways[v] + ways[u]) % mod;
                }
            }
        }

        return ways[n - 1];
    }
};