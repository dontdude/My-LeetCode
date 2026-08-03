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
    TreeNode* constructTree(int& p, vector<int>& pst, int is, int ie, vector<int>& in, unordered_map<int, int>& hashMap) {
        if(is > ie)  return nullptr;

        TreeNode* node = new TreeNode(pst[p]);
        int bp = hashMap[pst[p]];
        p--;

        node->right = constructTree(p, pst, bp + 1, ie, in, hashMap);
        node->left = constructTree(p, pst, is, bp - 1, in, hashMap);

        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = postorder.size();

        unordered_map<int, int> hashMap;
        for(int i = 0; i < n; i++) {
            hashMap[inorder[i]] = i;
        }

        int p = n - 1;
        return constructTree(p, postorder, 0, n - 1, inorder, hashMap);
    }
};