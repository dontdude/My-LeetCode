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
    TreeNode* constructTree(int& pre, vector<int>& preorder, int ins, int ine, vector<int>& inorder) {
        if(ins > ine)  return nullptr;

        int in = ins;
        while(in <= ine) {
            if(preorder[pre] == inorder[in])  break;
            in++;
        }

        if(in > ine)  return nullptr;

        TreeNode* node = new TreeNode(inorder[in]);
        pre++;

        node->left = constructTree(pre, preorder, ins, in - 1, inorder);
        node->right = constructTree(pre, preorder, in + 1, ine, inorder);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre = 0;
        return constructTree(pre, preorder, 0, inorder.size() - 1, inorder);
    }
};