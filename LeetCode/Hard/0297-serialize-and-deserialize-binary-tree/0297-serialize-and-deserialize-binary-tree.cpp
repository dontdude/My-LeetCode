/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == NULL)  return ""; 

        string serialized = "";
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {  // level order serializer
            TreeNode* node = q.front();    q.pop();

            if(node == NULL) {
                serialized += "#,";
                continue;
            }

            serialized += to_string(node->val) + ",";

            q.push(node->left);
            q.push(node->right);
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)  return NULL;

        queue<TreeNode*> q;
        stringstream s(data);
        string curs;
        getline(s, curs, ',');

        TreeNode* root = new TreeNode(stoi(curs));
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();   q.pop();

            getline(s, curs, ',');
            if(curs == "#") {
                node->left = NULL;
            } else if(curs.size() > 0) {
                node->left = new TreeNode(stoi(curs));
                q.push(node->left);
            }

            getline(s, curs, ',');
            if(curs == "#") {
                node->right = NULL;
            } else if(curs.size() > 0) {
                node->right = new TreeNode(stoi(curs));
                q.push(node->right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));