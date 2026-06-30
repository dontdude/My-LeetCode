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
    void flatten(TreeNode* root) { // do simple preorder traversal + prev node connection
        if(root == nullptr) return;
        stack<TreeNode*> st;

        TreeNode* prev = nullptr;
        st.push(root);

        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();

            if(prev)  {
                prev->right = node;
                prev->left = nullptr;
            }
            prev = node;

            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
        }
    }
};