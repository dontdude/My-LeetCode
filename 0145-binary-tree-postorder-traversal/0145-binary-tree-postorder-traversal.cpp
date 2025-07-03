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
    // Recursive solution: 
    //   vector<int> res;
    // vector<int> postorderTraversal(TreeNode* root) {
    //     postorderTraversal(root->left);
    //     postorderTraversal(root->right);
    //     res.push_back(root->val);
    //     return res;
    // }

    // Iterative solution: (write code for preorder, (just, here left call made before right) -> reverse result array)
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        if(root) st.push(root);

        while(!st.empty()) {
            TreeNode* curr = st.top();   st.pop();
            res.push_back(curr->val);
            
            if(curr->left)  st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }
        reverse(res.begin(), res.end());

        return res;
    }
};