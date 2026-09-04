class Solution {
    class DSU {
        int n;
        vector<int> Parent;
        vector<int> Size;
    
    public:
        DSU(int _n) {
            n = _n;
            Parent.resize(n, -1);
            Size.resize(n, 0);
        }
    
        int find(int u) {
            if(Parent[u] == -1)  return u;
            return Parent[u] = find(Parent[u]);
        }

        bool Union(int u, int v) {
            int ultu = find(u);
            int ultv = find(v);

            if(ultu == ultv) return false;

            if(Size[ultu] > Size[ultv]) swap(ultu, ultv);

            Parent[ultv] = ultu;
            Size[ultu] += Size[ultv];

            return true;
        }
    };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n - 1 > connections.size()) return -1;

        int connectedComponents = n;
        DSU dsu(n);

        for(const auto& connection : connections) {
            if(dsu.Union(connection[0], connection[1]))  connectedComponents--;
        }

        return connectedComponents - 1;
    }
};