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
    TreeNode* curr;
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    
    int next() {
        if(!hasNext()) return -1;

        while(curr) {
            st.push(curr);
            curr = curr->left;
        }

        TreeNode* node = st.top();
        st.pop();
        
        if(node->right) curr = node->right;

        return node->val;
    }
    
    bool hasNext() {
        return curr || !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */