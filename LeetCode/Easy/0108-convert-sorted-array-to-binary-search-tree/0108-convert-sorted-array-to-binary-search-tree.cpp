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
    TreeNode* dfs(int l, int r, vector<int>& nums) {
        if(l > r) return nullptr;
        
        int m = l + (r - l) / 2;
        TreeNode* node = new TreeNode(nums[m]);

        node->left = dfs(l, m - 1, nums);
        node->right = dfs(m + 1, r, nums);

        return node;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return dfs(0, nums.size() - 1, nums);
    }
};