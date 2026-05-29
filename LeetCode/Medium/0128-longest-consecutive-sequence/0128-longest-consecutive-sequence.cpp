class Solution {
    class DSU {
        int maxUnionSize;
        unordered_map<int, int> parent;
        unordered_map<int, int> size;
    public:
        DSU() {
            maxUnionSize = 0;
            parent.clear();
            size.clear();
        }

        int getMaxUnionSize() {
            return maxUnionSize;
        }

        void addNode(int num) {
            if(parent.find(num) != parent.end())  return;

            parent[num] = num;
            size[num] = 1;
            maxUnionSize = max(maxUnionSize, 1);
        }

        int find(int num) {
            if(parent[num] == num) return num;
            return parent[num] = find(parent[num]);
        }

        void unite(int num1, int num2) {
            if(parent.find(num2) == parent.end())  return;

            int up1 = find(num1);
            int up2 = find(num2);

            if(up1 == up2)  return;

            if(size[up1] > size[up2]) {
                swap(up1, up2);
            } 

            parent[up2] = up1;
            size[up1] += size[up2];
            maxUnionSize = max(maxUnionSize, size[up1]);
        }
    };
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;

        for(const int& num : nums) {
            dsu.addNode(num);

            dsu.unite(num, num - 1);
            dsu.unite(num, num + 1);
        }

        return dsu.getMaxUnionSize();
    }
};