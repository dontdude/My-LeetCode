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
    int result = INT_MIN;
    int findPath(TreeNode* node) {
        if(node == nullptr) return 0;

        int leftPath = findPath(node->left);
        int rightPath = findPath(node->right);

        result = max(result, node->val + max(leftPath, 0) + max(rightPath, 0));

        int currPath = max(node->val + max(leftPath, rightPath), node->val);
        result = max(result, currPath);

        return currPath;
    }
public:
    int maxPathSum(TreeNode* root) {
        return max(result, findPath(root));
    }
};