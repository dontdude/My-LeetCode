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
    int getToken(int& i, string& data) {
        if(data[i] == '#') {
            i += 2;
            return -1;
        }

        int num = 0;
        while(i < data.size() && data[i] != ',') {
            num *= 10;
            num += data[i] - '0';
            i++;
        }

        i++;
        return num;
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

            if(node == nullptr) {
                serialized.append("#,");
                continue;
            }

            serialized.append(to_string(node->val) + ',');
            q.push(node->left);
            q.push(node->right);
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        int rootToken = getToken(i, data);
        if(rootToken == -1)  return nullptr;

        TreeNode* root = new TreeNode(rootToken);
        queue<TreeNode*> q;
        q.push(root);

        while(i < data.size()) {
            TreeNode* node = q.front();
            q.pop();

            int leftToken = getToken(i, data);
            int rightToken = getToken(i, data);

            if(leftToken != -1) {
                TreeNode* leftNode = new TreeNode(leftToken);
                node->left = leftNode;
                q.push(leftNode);
            }

            if(rightToken != -1) {
                TreeNode* rightNode = new TreeNode(rightToken);
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;