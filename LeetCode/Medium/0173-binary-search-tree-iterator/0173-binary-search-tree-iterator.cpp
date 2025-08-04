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
class BSTIterator {
    stack<TreeNode*> myStack;

    void pushSmallerNodesFromCurrentSubtree(TreeNode* node) {
        while(node) {
            myStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushSmallerNodesFromCurrentSubtree(root);
    }
    
    int next() {
        TreeNode* curr = myStack.top();
        myStack.pop();

        pushSmallerNodesFromCurrentSubtree(curr->right);

        return curr->val;
    }
    
    bool hasNext() {
        return myStack.empty() == false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */