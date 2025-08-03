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
    TreeNode* findInorderPredessor(TreeNode* node) {
        TreeNode* curr = node->left;
        while(curr->right != NULL && curr->right != node) {
            curr = curr->right;
        }
        return curr;
    }
    void inorderTraversalWithIndex(int ind, int& res, int k, TreeNode* node) {
        if(node == NULL)  return;

        while(node) {
            if(node->left == NULL) {
                if(++ind == k)  res = node->val;
                node = node->right;
            } else {
                TreeNode* predessor = findInorderPredessor(node);
                if(predessor->right == node) {
                    if(++ind == k)  res = node->val;  // even if answer found.. we can't return yet.. we need to fix tree, in morris traversal (pred->right = node ie)
                    node = node->right;
                    predessor->right = NULL;
                } else {
                    predessor->right = node;
                    node = node->left;
                }
            }
        }
    }
    int kthSmallest(TreeNode* root, int k) {
        int ind = 0, res = 0;
        inorderTraversalWithIndex(ind, res, k, root);
        return res;
    }
};