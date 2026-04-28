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
    pair<int, int> dfs(TreeNode* node) {
        if(node == nullptr)  return {0, 0};

        pair<int, int> leftAmount = dfs(node->left);
        pair<int, int> rightAmount = dfs(node->right);

        int take = node->val + leftAmount.second + rightAmount.second;
        int not_take = max(leftAmount.first, leftAmount.second) + max(rightAmount.first, rightAmount.second);
        
        return {take, not_take};
    }
public:
    int rob(TreeNode* root) {
        if(root == nullptr)  return 0;
        pair<int, int> amounts = dfs(root);
        return max(amounts.first, amounts.second);
    }
};