/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    TreeNode* builder(int& ps, vector<int>& preorder, int is, int ie, vector<int>& inorder, unordered_map<int, int>& indexMap) {
        if(ps == preorder.size())  return NULL;

        TreeNode* node = new TreeNode(preorder[ps]);

        if(is == ie) return node;

        int icurr = indexMap[preorder[ps]];
        
        if(is <= icurr - 1) {
            ps++;
            node->left = builder(ps, preorder, is, icurr - 1, inorder, indexMap);
        }
        if(icurr + 1 <= ie) {
            ps++;
            node->right = builder(ps, preorder, icurr + 1, ie, inorder, indexMap);
        }

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indexMap;

        for(int i = 0; i < inorder.size(); i++) {
            indexMap[inorder[i]] = i;
        }

        int i = 0;
        return builder(i, preorder, 0, inorder.size() - 1, inorder, indexMap);
    }
};