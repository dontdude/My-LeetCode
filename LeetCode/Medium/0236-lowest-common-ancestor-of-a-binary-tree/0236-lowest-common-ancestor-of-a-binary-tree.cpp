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
        if(root == NULL)  return NULL;

        if(root == p || root == q) {
            return root;
        }

        TreeNode* leftNode = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightNode = lowestCommonAncestor(root->right, p, q);

        if((leftNode && rightNode) && ((leftNode == p && rightNode == q) || (leftNode == q && rightNode == p))) {
            return root;
        }

        if(leftNode)  return leftNode;
        else return rightNode;
    }
};