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
    // why recovering can work, even though level of tree is huge 20, meaning a lot of nodes in full tree, but there is also a constraints that limits number of nodes in tree to 10^4
    void recoverTree(TreeNode* node, int x) {
        if(node == nullptr)  return;

        node->val = x;
        hashNode.insert(x);

        if(node->left)  recoverTree(node->left, 2 * x + 1);
        if(node->right) recoverTree(node->right, 2 * x + 2);
    }
    TreeNode* rootNode;
    unordered_set<int> hashNode;
public:
    FindElements(TreeNode* root) {
        rootNode = root;
        recoverTree(root, 0);
    }
    
    bool find(int target) {
        return hashNode.find(target) != hashNode.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */