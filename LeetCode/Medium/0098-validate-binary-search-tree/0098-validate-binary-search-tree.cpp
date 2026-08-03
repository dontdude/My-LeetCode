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
    bool dfs(long long mn, long long mx, TreeNode* node) {
        if(node == nullptr) return true;

        if(mn >= node->val || node->val >= mx)  return false;

        return dfs(mn, node->val, node->left) && dfs(node->val, mx, node->right);
    } 
public:
    bool isValidBST(TreeNode* root) {
        return dfs(LLONG_MIN, LLONG_MAX, root);
    }
};