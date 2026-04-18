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
        while(root) {
            st.push(root);
            root = root->left;
        }

        TreeNode* curr;
        while(k > 0 && !st.empty()) {
            curr = st.top();  
            st.pop();
            k--;
            
            TreeNode* right = curr->right;
            while(right) {
                st.push(right);
                right = right->left;
            }
        }

        return curr->val;
    }
};