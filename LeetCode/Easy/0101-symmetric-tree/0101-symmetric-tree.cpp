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
    bool helper(TreeNode* object, TreeNode* image) {
        if(object == NULL || image == NULL)  return object == image;

        if(object->val != image->val)  return false;

        return helper(object->left, image->right) && helper(object->right, image->left);
    }

    bool isSymmetric(TreeNode* root) {
        if(root == NULL)  return true;
        return helper(root->left, root->right);
    }
};