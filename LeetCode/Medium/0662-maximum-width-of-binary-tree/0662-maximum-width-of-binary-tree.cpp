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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)  return 0;

        int res = 0;
        queue<pair<TreeNode*, long long>> q;  // long long still required.. because node at each level even after starting from 1, can reach to a very large not getting accumated in long long, in current level only. example check past solutions. 

        q.push({root, 0});

        while(!q.empty()) {
            int sz = q.size();
            long long lvlMinIdx = q.front().second;  // for 1st root level it is 0, for all other level it is value of first index of node. (not 1 always btw, it can be 2 or whatever based on whether that index node actually exsist or not)
            int minIdxInCurrLvl = 0, maxIdxInCurrLvl = 0;

            for(int i = 0; i < sz; i++) {
                TreeNode* node = q.front().first;
                long long index = q.front().second - lvlMinIdx;  // to make the id start from 0 
                q.pop();

                if(i == 0)  minIdxInCurrLvl = index;
                if(i == sz - 1)  maxIdxInCurrLvl = index;

                long long leftChildIndex = 2*index + 1;
                long long rightChildIndex = 2*index + 2;

                if(node->left) {
                    q.push({node->left, leftChildIndex});
                } 
                if(node->right) {
                    q.push({node->right, rightChildIndex});
                }
            }
            
            res = max(res, maxIdxInCurrLvl - minIdxInCurrLvl + 1);
        }

        return res;
    }
};