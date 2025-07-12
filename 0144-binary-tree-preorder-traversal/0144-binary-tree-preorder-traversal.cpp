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
    // Morris preorder traversal
    TreeNode* findPredessor(TreeNode* node) {
        TreeNode* curr = node->left;
        while(curr->right != NULL && curr->right != node) {
            curr = curr->right;
        }
        return curr;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;

        while(curr) {
            if(curr->left == NULL) {
                res.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* pred = findPredessor(curr);

                if(pred->right == NULL) {
                    res.push_back(curr->val);
                    pred->right = curr;
                    curr = curr->left;
                } else if(pred->right == curr) {
                    pred->right = NULL;
                    curr = curr->right;
                }
            }
        }

        return res;
    }
};