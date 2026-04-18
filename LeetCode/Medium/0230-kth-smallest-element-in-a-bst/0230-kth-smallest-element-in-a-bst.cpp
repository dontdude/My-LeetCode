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
            bool goingToParent = false;
            if(node == nullptr) {
                if(st.empty())  break;
                goingToParent = true;
                node = st.top();
                st.pop();
            }
            
            if(node->left == nullptr || goingToParent) {
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