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
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == nullptr) return {};

        vector<int> res;
        stack<pair<TreeNode*, char>> st;
        st.push({root, 0});

        while(!st.empty()) {
            TreeNode* node = st.top().first;
            char vis = st.top().second;
            st.pop();
            
            if(vis == 0) {
                st.push({node, 1});
                if(node->right) st.push({node->right, 0});
                if(node->left) st.push({node->left, 0});
            } else {
                res.push_back(node->val);
            }
        }

        return res;
    }
};