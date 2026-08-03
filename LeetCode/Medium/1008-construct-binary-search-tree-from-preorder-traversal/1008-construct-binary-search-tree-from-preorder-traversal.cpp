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
    TreeNode* dfs(int p, int e, vector<int>& pre) {
        if(p > e)  return nullptr;

        int val = pre[p++];
        TreeNode* node = new TreeNode(val);
        
        int bp = p;
        while(bp <= e && pre[bp] < val) bp++;

        node->left = dfs(p, bp - 1, pre);
        node->right = dfs(bp, e, pre);

        return node;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return dfs(0, preorder.size() - 1, preorder);
    }
};