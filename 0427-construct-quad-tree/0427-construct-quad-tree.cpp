/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* quadTree(int x, int y, int n, vector<vector<int>>& prefixSum){
        int lx = x + n -1, ly = y + n - 1;

        int totalOne = prefixSum[lx][ly];
        if(x)  totalOne -= prefixSum[x - 1][ly];
        if(y)  totalOne -= prefixSum[lx][y - 1];
        if(x && y)  totalOne += prefixSum[x-1][y-1];

        if(totalOne == n*n || totalOne == 0)  {
            return new Node(totalOne != 0, true);
        } 

        int newn = (n>>1);
        Node* topLeft = quadTree(x, y, newn, prefixSum);
        Node* topRight = quadTree(x, y + newn, newn, prefixSum);
        Node* bottomLeft = quadTree(x + newn, y, newn, prefixSum);
        Node* bottomRight = quadTree(x + newn, y + newn, newn, prefixSum);

        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }

    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> prefixSum = grid;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
               if(i)  prefixSum[i][j] += prefixSum[i-1][j];
               if(j)  prefixSum[i][j] += prefixSum[i][j-1];
               if(i && j)  prefixSum[i][j] -= prefixSum[i-1][j-1];
            }
        }

        return quadTree(0, 0, n, prefixSum);
    }
};