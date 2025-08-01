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
    void flatten(TreeNode* root) {
        if(root == NULL)  return;

        TreeNode* dummy = new TreeNode(-1);
        TreeNode* prev = dummy;

        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();  st.pop();

            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);

            prev->right = node;
            prev = node;
            prev->left = NULL;
        }

        dummy->right = NULL;
        delete dummy;
    }
};