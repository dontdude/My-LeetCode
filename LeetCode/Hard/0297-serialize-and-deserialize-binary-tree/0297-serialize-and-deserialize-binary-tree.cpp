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
    string getNodeToken(string& s) {
        string nodeToken = "";
        int i = 0;
        while(i < s.size() && s[i] != ',') {
            nodeToken.push_back(s[i++]);
        }

        s = s.substr(i + 1);

        return nodeToken;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL) {
                serialized.append("#,");
                continue;
            }

            string val = to_string(node->val);
            serialized.append(val + ",");

            q.push(node->left);
            q.push(node->right);
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string rootToken = getNodeToken(data);
        if(rootToken == "#") return NULL;

        TreeNode* root = new TreeNode(stoi(rootToken));

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            string leftToken = getNodeToken(data);
            string rightToken = getNodeToken(data);

            if(leftToken != "#") {
                TreeNode* left = new TreeNode(stoi(leftToken));
                node->left = left;
                q.push(left);
            }

            if(rightToken != "#") {
                TreeNode* right = new TreeNode(stoi(rightToken));
                node->right = right;
                q.push(right);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));