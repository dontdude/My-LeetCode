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
public:
    int helper(TreeNode* node, int& res) {
        if(node == NULL) return 0;

        int leftPath = max(0, helper(node->left, res));
        int rightPath = max(0, helper(node->right, res));

        res = max(res, leftPath + rightPath + node->val);

        return max(leftPath, rightPath) + node->val;
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
};