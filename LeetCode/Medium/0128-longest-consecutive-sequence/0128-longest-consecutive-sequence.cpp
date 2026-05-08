class Solution {
    class DSU {
        int maxSizeTree;
        unordered_map<int, int> parent;
        unordered_map<int, int> size;

    public:
        DSU() {
            maxSizeTree = 0;
        }

        bool isNodePresent(int num) {
            return parent.find(num) != parent.end();
        }

        int getMaxSize() {
            return maxSizeTree;
        }

        void add(int num) {
            parent[num] = num;
            size[num] = 1;
            maxSizeTree = max(maxSizeTree, size[num]);
        }

        int find(int num) {
            if(parent[num] == num)  return num;

            return parent[num] = find(parent[num]);
        }

        void unite(int i, int j) {
            int upi = find(i); // ultimate parent of i
            int upj = find(j);

            if(upi != upj) {
                if(size[upi] < size[upj])  swap(upi, upj);

                parent[upj] = upi;
                size[upi] += size[upj];
                maxSizeTree = max(maxSizeTree, size[upi]);
            }
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;

        for(const auto& num : nums) {
            if(dsu.isNodePresent(num))  continue;

            dsu.add(num);

            if(dsu.isNodePresent(num + 1)) dsu.unite(num, num + 1);
            if(dsu.isNodePresent(num - 1)) dsu.unite(num, num - 1);
        }

        return dsu.getMaxSize();
    }
};