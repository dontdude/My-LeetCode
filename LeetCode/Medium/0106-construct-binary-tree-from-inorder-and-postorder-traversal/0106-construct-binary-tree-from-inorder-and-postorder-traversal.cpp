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
    TreeNode* helper(int& posti, int ins, int ine, vector<int>& in, vector<int>& post, unordered_map<int, int>& inorderMap) {
        if(ins > ine) return NULL;

        int val = post[posti];
        posti--;

        TreeNode* node = new TreeNode(val);

        int ini = inorderMap[val];

        node->right = helper(posti, ini + 1, ine, in, post, inorderMap);
        node->left  = helper(posti, ins, ini - 1, in, post, inorderMap);

        return node;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int insz = inorder.size() - 1, postIndex = postorder.size() - 1;
        unordered_map<int, int> inorderMap;

        for(int i = 0; i <= insz; i++) {
            inorderMap[inorder[i]] = i;
        }

        return helper(postIndex, 0, insz, inorder, postorder, inorderMap);
    }
};