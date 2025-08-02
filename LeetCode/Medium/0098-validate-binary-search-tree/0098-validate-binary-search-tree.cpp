/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool helper(long long rangeStart, long long rangeEnd, TreeNode* node) {
        if (node == NULL)
            return true;
        if (rangeStart > rangeEnd)
            return false;

        if (rangeStart >= node->val || node->val >= rangeEnd)
            return false;

        return helper(rangeStart, node->val, node->left) &&
               helper(node->val, rangeEnd, node->right);
    }
    bool isValidBST(TreeNode* root) { return helper(LLONG_MIN, LLONG_MAX, root); }
};