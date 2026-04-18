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
    // Note: Let the morris traversal finish, even if answer found, else thread would still be there. 
    TreeNode* findPredecessor(TreeNode* node) {
        TreeNode* curr = node->left;

        while(curr->right != nullptr && curr->right != node) {
            curr = curr->right;
        }

        return curr;
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        TreeNode* node = root;
        int res = -1;

        while(node) {
            if(node->left == nullptr) {
                if(--k == 0) res = node->val;
                node = node->right; 
            } else {
                TreeNode* pre = findPredecessor(node);

                if(pre->right == nullptr) {
                    pre->right = node;
                    node = node->left;
                } else if(pre->right == node) {
                    if(--k == 0)  res = node->val;
                    pre->right = nullptr;
                    node = node->right;
                }
            }
        }

        return res;
    }
};