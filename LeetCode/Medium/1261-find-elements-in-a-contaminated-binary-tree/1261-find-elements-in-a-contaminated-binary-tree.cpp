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
class FindElements {
    vector<int> nodeVals;
public:
    FindElements(TreeNode* root) {
        if(root == nullptr) return;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        nodeVals.push_back(0);

        while(!q.empty()) {
            TreeNode* node = q.front().first;
            int x = q.front().second;
            q.pop();

            if(node->left) {
                int leftNodeVal = 2 * x + 1;
                nodeVals.push_back(leftNodeVal);
                q.push({node->left, leftNodeVal});
            }

            if(node->right) {
                int rightNodeVal = 2 * x + 2;
                nodeVals.push_back(rightNodeVal);
                q.push({node->right, rightNodeVal});
            }
        }
    }
    
    bool find(int target) {
        auto it = lower_bound(nodeVals.begin(), nodeVals.end(), target);
        return it != nodeVals.end() && *it == target;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */