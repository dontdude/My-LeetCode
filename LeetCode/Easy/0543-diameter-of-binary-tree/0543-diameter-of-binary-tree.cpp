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
    int maxDiameter;

    int dfs(TreeNode* node) {
        if(node == nullptr)  return 0;

        int lh = dfs(node->left);
        int rh = dfs(node->right);

        maxDiameter = max(maxDiameter, lh + rh);

        return 1 + max(lh, rh);
    }
public:
    Solution() {
        maxDiameter = 0;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxDiameter;
    }
};