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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mp;
        postOrder(root, mp, res);
        return res;
    }

    string postOrder(TreeNode* curr, unordered_map<string, int>& mp, vector<TreeNode*>& res){
        if(curr == NULL)  return "";
        string currentSubtree = to_string(curr->val) + '-' + postOrder(curr->left, mp, res) + '-' +  postOrder(curr->right, mp, res); 
        mp[currentSubtree]++;
        if(mp[currentSubtree] == 2)  res.push_back(curr); 
        return currentSubtree; 
    }
};