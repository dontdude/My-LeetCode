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
        map<int, map<int, multiset<int>>> nodes;   // vertical, level, nodes
        // At each vertical, we can have multiple levels, and here in each level we can have multiple nodes
        // multiset, to store duplicate values in sorted orders
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});   // node, vertical, level

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int v = q.front().second.first;
            int l = q.front().second.second;
            q.pop();


            nodes[v][l].insert(node->val); 

            if(node->left) {
                q.push({node->left, {v - 1, l + 1}});
            } 
            if(node->right) {
                q.push({node->right, {v + 1, l + 1}});
            }
        }


        vector<vector<int>> res;
        for(auto levels: nodes) {
            vector<int> col;
            for(auto nodeList: levels.second) {
                for(auto node: nodeList.second) {
                    col.push_back(node);
                }
            }
            res.push_back(col);
        }

        return res;
    }
};