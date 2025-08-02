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
    TreeNode* helper(int s, int e, vector<int>& nums) {
        if (s > e)
            return NULL;

        int m = (e - s) / 2 + s;
        TreeNode* node = new TreeNode(nums[m]);

        node->left = helper(s, m - 1, nums);
        node->right = helper(m + 1, e, nums);

        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(0, nums.size() - 1, nums);
    }
};