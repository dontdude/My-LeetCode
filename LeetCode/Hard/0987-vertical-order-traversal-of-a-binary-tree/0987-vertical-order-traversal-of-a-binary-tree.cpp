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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, vector<int>>> matrix;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int v = q.front().second.first; //vertical
            int l = q.front().second.second; // level
            q.pop();

            matrix[v][l].push_back(node->val);


            if(node->left)  q.push({node->left, {v - 1, l + 1}});
            if(node->right) q.push({node->right, {v + 1, l + 1}});
        }

        vector<vector<int>> res;

        for(auto& [verticalMap, levelMap] : matrix) {
            vector<int> vertical;
            for(auto& [level, list] : levelMap) {
                sort(list.begin(), list.end());
                vertical.insert(vertical.end(), list.begin(), list.end());
            }
            res.push_back(vertical);
        }

        return res;
    }
};