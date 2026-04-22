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
    bool dfs(TreeNode* node, long long mx, long long mn) {
        if(node == nullptr) return true;
        if(node->val <= mn || node->val >= mx)  return false;

        return dfs(node->left, node->val, mn) && dfs(node->right, mx, node->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LLONG_MAX, LLONG_MIN);
    }
};