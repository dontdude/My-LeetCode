class DSU {
public: 
    unordered_map<int, int> parent;
    unordered_map<int, int> size;

    DSU () {
        parent.clear();
        size.clear();
    }

    bool isNodeInDSU(int num) {
        return parent.find(num) != parent.end();
    }

    void createNode(int num) {
        parent[num] = num;
        size[num] = 1;
    }

    int find(int num) {
        if(parent[num] == num)  return num;
        return parent[num] = find(parent[num]);  
    }

    int unite(int s1, int s2) {
        int root1 = find(s1);
        int root2 = find(s2);

        if(root1 != root2) {
            if(size[root1] > size[root2]) {
                parent[root2] = root1;
                size[root1] += size[root2];
                return size[root1];
            } else {
                parent[root1] = root2;
                size[root2] += size[root1];
                return size[root2];
            }
        }

        return size[root1];
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        DSU dsu;
        int res = 0;
        
        for(int num : nums) {
            if(dsu.isNodeInDSU(num))  continue;

            dsu.createNode(num);

            if(dsu.isNodeInDSU(num - 1)) {
                res = max(res, dsu.unite(num, num - 1));
            } 

            if(dsu.isNodeInDSU(num + 1)) {
                res = max(res, dsu.unite(num, num + 1));
            }
        }

        return res;
    }
};