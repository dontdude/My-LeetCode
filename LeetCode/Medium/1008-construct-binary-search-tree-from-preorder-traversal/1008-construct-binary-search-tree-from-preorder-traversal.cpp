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
    TreeNode* constructBST(int mn, int mx, int& i, vector<int>& preorder) {
        if(i >= preorder.size()) return nullptr;

        int val = preorder[i];
        if(val < mn || val > mx)  return nullptr;

        TreeNode* node = new TreeNode(val);
        i++;

        node->left = constructBST(mn, val, i, preorder);
        node->right = constructBST(val, mx, i, preorder);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() < 1)  return nullptr;
        int start = 0;
        return constructBST(INT_MIN, INT_MAX, start, preorder);
    }
};