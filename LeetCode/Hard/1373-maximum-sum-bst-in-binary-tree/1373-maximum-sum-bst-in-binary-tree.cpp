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
class NodeValue {
public:
    int minNode, maxNode, sumBSTs;

    NodeValue(int sum, int mn, int mx) {
        sumBSTs = sum;
        minNode = mn;
        maxNode = mx;
    }
};
class Solution {
public:
    NodeValue helper(int& res, TreeNode* node) {
        if (node == NULL)
            return NodeValue(0, INT_MAX, INT_MIN);

        NodeValue left = helper(res, node->left);
        NodeValue right = helper(res, node->right);

        if (left.maxNode < node->val && node->val < right.minNode) {
            int cur_sum = node->val + left.sumBSTs + right.sumBSTs;
            int cur_min_value = min(left.minNode, node->val); 
            int cur_max_value = max(right.maxNode, node->val);
            
            res = max(res, cur_sum);
            return NodeValue(cur_sum, cur_min_value, cur_max_value);
        }

        return NodeValue(max(left.sumBSTs, right.sumBSTs), INT_MIN, INT_MAX);
    }
    int maxSumBST(TreeNode* root) { 
        int res = 0;
        helper(res, root);  
        return res;
    }
};