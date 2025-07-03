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
    // Recursive Solution:
    // vector<int> res;
    // vector<int> inorderTraversal(TreeNode* root) {
    //     if(root == NULL) return res;

    //     inorderTraversal(root->left);   // traverse all the node in left, by breaking the control flow, to reach last
    //     res.push_back(root->val);        
    //     inorderTraversal(root->right);  // traverse all the node in right, by breaking the control flow

    //     return res;
    // }

    // Iterative Solution:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr || !st.empty()) {
            while(curr) {               
                st.push(curr);
                curr = curr->left;      // traverse all the node in left, loop here breaks the control flow, to reach last
            }

            curr = st.top();   st.pop();
            res.push_back(curr->val);

            curr = curr->right;          // traverse all the node of right, auto breaks the control flow.. since last line
        }

        return res;
    }
};