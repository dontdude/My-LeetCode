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
class CBTInserter {
    TreeNode* rootNode;
    queue<TreeNode*> q;

    int getHeight(TreeNode* node) {
        if(node == nullptr) return 0;
        return 1 + getHeight(node->left);  // since complete binary tree, so max height is always in left node
    }
public:
    CBTInserter(TreeNode* root) {
        if(root != nullptr) q.push(root);
        rootNode = root;

        int height = getHeight(root);

        while(!q.empty()) {
            int size = q.size();
            if(--height)  break;  // parent level of leaf level nodes
            
            for(int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);

        if(q.empty()) {
            q.push(rootNode);  // if no node in queue, then that means we only have rootnode given
        }

        while(!q.empty()) { 
            TreeNode* node = q.front();

            if(node->left == nullptr) {
                node->left = newNode;
                q.push(newNode);
                return node->val;
            } else {
                q.push(node->left);
            }
            
            if(node->right == nullptr) {
                node->right = newNode;
                q.push(newNode);
                return node->val;
            } else {
                q.push(node->right);
            }

            q.pop();  // popping only when both left and right child of node are there
        }

        return -1;
    }
    
    TreeNode* get_root() {
        return rootNode;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */