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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* node = root;

        while(k > 0) {
            if(node == nullptr) {
                if(st.empty())  break;
                node = st.top();
            }

            if(node->left == nullptr) {
                if(--k == 0) return node->val;
                node = node->right;
            } else {
                st.push(node);
                node = node->left;
            }
        }

        return -1;
    }
};