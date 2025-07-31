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
    TreeNode* helper(int& preIndex, int inStart, int inEnd, vector<int>& pre, vector<int>& in, unordered_map<int, int>& inorderMap) {
        if(inStart > inEnd)  return NULL;

        int val = pre[preIndex];
        preIndex++; // CRITICAL: preindex in pass by refernce notice in the parameters, this is because.. after traversing all the left. we want the updated values of preIndex to traverse all the right, not what the parent has

        TreeNode* node = new TreeNode(val);

        int inIndex = inorderMap[val];

        node->left = helper(preIndex, inStart, inIndex - 1, pre, in, inorderMap);  //called with next preorder node val, and left part of inorder
        node->right = helper(preIndex, inIndex + 1, inEnd, pre, in, inorderMap);  // called with next preorder node val, and right part of inorder

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int insz = inorder.size(), preIndex = 0;
        unordered_map<int, int> inorderMap;  // to quickly find the index in inorder, against a value

        for(int i = 0; i < insz; i++) {
           inorderMap[inorder[i]] = i;
        }

        return helper(preIndex, 0, insz - 1, preorder, inorder, inorderMap);
    }
};