class Solution {
   class DSU {
        int n;
        vector<int> parent;
        vector<int> size;
    public: 
        DSU(int n) {
            this->n = n;
            this->parent.resize(n, -1);
            this->size.resize(n, 0);
        } 

        int find(int u) {
            if(parent[u] == -1) return u;
            return parent[u] = find(parent[u]);
        }

        bool unite(int u, int v) {
            int ultu = find(u);
            int ultv = find(v);

            if(ultu == ultv)  return false;

            if(size[ultu] > size[ultv]) {
                parent[ultv] = ultu;
                size[ultu] += size[ultv];
            } else {
                parent[ultu] = ultv;
                size[ultv] += size[ultu];
            }

            return true;
        }
   };
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        
        DSU dsu(n);
        int connectedComponents = n;

        for(const auto& connection : connections) {
            if(dsu.unite(connection[0], connection[1]))  connectedComponents--;
        }

        return connectedComponents - 1;
    }
};