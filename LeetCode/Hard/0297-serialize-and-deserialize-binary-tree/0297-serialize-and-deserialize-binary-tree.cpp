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
    int getNodeToken(string& data, int& i) {
        if(data[i] == '1' && data[i + 1] == '#')  {
            i += 2;
            return INT_MIN;
        }

        int tokenSize = 0;
        while(data[i] != '_') { 
            tokenSize *= 10;
            tokenSize += (data[i] - '0');
            i++;
        }

        i++;   
        int token = 0;
        int sign = 1;
        if(data[i] == '-') {
            sign = -1;
            i++;
            tokenSize--;
        }

        while(tokenSize--) { 
            token *= 10;
            token += (data[i] - '0');
            i++;
        }

        return sign * token;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr)  return "1#";

        queue<TreeNode*> q;
        q.push(root);
        string s = "";

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node == nullptr) {
                s.append("1#");
                continue;
            }

            string nodeToken = to_string(node->val);
            string tokenSize = to_string(nodeToken.size());
            s.append(tokenSize + '_' + nodeToken);

            q.push(node->left);
            q.push(node->right);
        }

        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        int nodeToken = getNodeToken(data, i);

        if(nodeToken == INT_MIN) return nullptr;

        TreeNode* root = new TreeNode(nodeToken);
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            int leftNodeToken = getNodeToken(data, i);
            if(leftNodeToken != INT_MIN) {
                TreeNode* leftNode = new TreeNode(leftNodeToken);
                node->left = leftNode;
                q.push(leftNode);
            }

            int rightNodeToken = getNodeToken(data, i);
            if(rightNodeToken != INT_MIN) {
                TreeNode* rightNode = new TreeNode(rightNodeToken);
                node->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));