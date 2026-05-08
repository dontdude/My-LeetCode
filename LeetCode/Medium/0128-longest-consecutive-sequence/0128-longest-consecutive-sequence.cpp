class Solution {
    class DSU {
        int maxSizeTree;
        unordered_map<int, int> parent;
        unordered_map<int, int> size;

    public:
        DSU() {
            maxSizeTree = 0;
        }

        int getMaxSize() {
            return maxSizeTree;
        }

        void add(int num) {
            if(parent.find(num) != parent.end())  return;
            parent[num] = num;
            size[num] = 1;
            maxSizeTree = max(maxSizeTree, size[num]);
        }

        int find(int num) {
            if(parent[num] == num)  return num;

            return parent[num] = find(parent[num]);
        }

        void unite(int i, int j) {
            if(parent.find(j) == parent.end())  return;
            int upi = find(i);
            int upj = find(j);

            if(upi == upj) return;

            if(size[upi] < size[upj]) {
                parent[upj] = upi;
                size[upi] += size[upj];
                maxSizeTree = max(maxSizeTree, size[upi]);
            } else {
                parent[upi] = upj;
                size[upj] += size[upi];
                maxSizeTree = max(maxSizeTree, size[upj]);
            }
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;

        for(int num : nums) {
            dsu.add(num);

            dsu.unite(num, num + 1);
            dsu.unite(num, num - 1);
        }

        return dsu.getMaxSize();
    }
};