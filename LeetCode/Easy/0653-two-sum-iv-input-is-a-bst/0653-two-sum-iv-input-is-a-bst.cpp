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
    bool findTarget(TreeNode* root, int k) {
        TreeNode *curr1 = root, *curr2 = root;
        stack<TreeNode*> smallSt, largeSt;

        while((curr1 || !smallSt.empty()) && (curr2 || !largeSt.empty())) {
            while(curr1) {
                smallSt.push(curr1);
                curr1 = curr1->left;
            }

            while(curr2) {
                largeSt.push(curr2);
                curr2 = curr2->right;
            }

            TreeNode* small = smallSt.top();
            TreeNode* large = largeSt.top();
            if(small == large)  return false;

            int sum = small->val + large->val;

            if(sum == k) {
                return true;
            } else if(sum < k) {
                smallSt.pop();
                if(small->right)  curr1 = small->right;
            } else {
                largeSt.pop();
                if(large->left) curr2 = large->left;
            }
        }

        return false;
    }
};