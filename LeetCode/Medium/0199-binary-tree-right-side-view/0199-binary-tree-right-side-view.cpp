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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};
        vector<int> res;

        queue<TreeNode*> q;
        TreeNode* prev = nullptr;
        q.push(root);
        q.push(nullptr);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) {
                if(prev) res.push_back(prev->val);
                if(!q.empty())  q.push(nullptr);
                continue;
            }

            if(node->left)  q.push(node->left);
            if(node->right) q.push(node->right);
            prev = node;
        }

        return res;
    }
};