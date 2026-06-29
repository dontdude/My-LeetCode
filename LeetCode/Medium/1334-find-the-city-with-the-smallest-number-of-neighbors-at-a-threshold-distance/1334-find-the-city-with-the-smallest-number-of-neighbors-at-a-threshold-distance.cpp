class Solution {
    void dijkstra(int s, vector<vector<pair<int, int>>>& graph, vector<vector<int>>& dist, int& distanceThreshold) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[s][s] = 0;
        pq.push({0, s});

        while(!pq.empty()) {
            int node = pq.top().second;
            pq.pop();

            for(const auto& edge : graph[node]) {
                int nebr = edge.first;
                int wt = edge.second;

                int possibleNebrDistance = dist[s][node] + wt;

                if(dist[s][nebr] > possibleNebrDistance && possibleNebrDistance <= distanceThreshold) {
                    dist[s][nebr] = possibleNebrDistance;
                    pq.push({dist[s][nebr], nebr});
                }
            }
        }
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> graph(n);
        for(const auto& edge : edges) {
            graph[edge[0]].push_back({edge[1], edge[2]});
            graph[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for(int i = 0; i < n; i++) {
            dijkstra(i, graph, dist, distanceThreshold);
        }

        int resCity = 0, minValidNebr = n;
        for(int i = 0; i < n; i++) {
            int validNebr = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && dist[i][j] <= distanceThreshold) validNebr++;
            } 

            if(validNebr <= minValidNebr) {
                minValidNebr = validNebr;
                resCity = i;
            }
        }

        return resCity;
    }
};