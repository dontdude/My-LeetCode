class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());

        for(const auto& flight : flights) {
            graph[flight[0]].push_back({flight[1], flight[2]});
        }

        vector<int> prices(n, INT_MAX);
        queue<pair<int, int>> q;

        q.push({src, 0});
        prices[src] = 0;
        int level = 0;

        while(!q.empty() && level <= k) {
            int s = q.size();
            level++;

            while(s--) {
                int u = q.front().first;
                int d = q.front().second;
                q.pop();

                if(prices[u] >= prices[dst]) continue;

                for(const auto& nebr : graph[u]) {
                    int v = nebr.first;
                    int price = nebr.second;

                    if(prices[v] > d + price) {
                        prices[v] = min(prices[v], d + price);
                        q.push({v, d + price});
                    }
                }
            }
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};