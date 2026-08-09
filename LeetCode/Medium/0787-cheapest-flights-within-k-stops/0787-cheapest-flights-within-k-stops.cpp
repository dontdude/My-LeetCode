class Solution {
public:
    // using bellman ford: each iteration i, is basically the number of edges used now to get new dist
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int  edgesRequiredForKStops = k + 1;
        
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i = 0; i < edgesRequiredForKStops; i++) {

            // prevents taking multiple flights in a single step (if i = 1, then calc for only flight using 1 edge)
            vector<int> temp = dist;

            for(const auto&flight : flights) {
                int u = flight[0];
                int v = flight[1];
                int currDist = flight[2];
                
                if(dist[u] != INT_MAX && temp[v] > dist[u] + currDist) {
                    temp[v] = dist[u] + currDist;
                }
            }

            dist = temp;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};