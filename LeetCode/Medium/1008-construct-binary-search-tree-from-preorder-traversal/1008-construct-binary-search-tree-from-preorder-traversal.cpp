/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int ceilIndex(int s, int e, int val, vector<int>& pre) {
        for (int i = s; i <= e; i++) {
            if (pre[i] > val)
                return i;
        }
        return e + 1;  // if no breakpoint found.. then e + 1 is my breakpoint (only left subtree element reamins )
    }
    TreeNode* helper(int s, int e, vector<int>& pre) {
        if (s > e)
            return NULL;

        TreeNode* node = new TreeNode(pre[s]);
        int breakpoint = ceilIndex(s + 1, e, pre[s], pre);

        node->left = helper(s + 1, breakpoint - 1, pre);
        node->right = helper(breakpoint, e, pre);

        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(0, preorder.size() - 1, preorder);
    }
};