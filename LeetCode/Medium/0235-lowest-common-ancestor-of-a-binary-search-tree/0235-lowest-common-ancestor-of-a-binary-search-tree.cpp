/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return NULL;

        int smaller = min(p->val, q->val);
        int larger = max(p->val, q->val);

        if (smaller < root->val && root->val < larger)
            return root;
        else if (smaller == root->val || root->val == larger)
            return root;
        else if (root->val > larger)
            return lowestCommonAncestor(root->left, p, q);
        else
            return lowestCommonAncestor(root->right, p, q);
    }
};