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
    int getNextVal(int& i, string& data) {
        if(data[i] == '#' || i >= data.size()) {
            i += 2;
            return INT_MIN;
        }

        int sign = 1;
        if(data[i] == '-') {
            i++;
            sign = -1;
        }

        int val = 0;
        while(i < data.size() && data[i] != ',') {
            val *= 10;
            val += data[i] - '0';
            i++;
        }

        i++;
        return sign * val;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serialized = "";

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();

            if(curr == NULL) {
                serialized.append("#,");
                continue;
            }

            string val = to_string(curr->val);
            serialized.append(val + ',');

            q.push(curr->left);
            q.push(curr->right);
        }

        return serialized;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        int rootVal = getNextVal(i, data);
        if(rootVal == INT_MIN) return NULL;

        TreeNode* root = new TreeNode(rootVal); 

        queue<TreeNode*> q;
        q.push(root);

        while(i < data.size()) {
            TreeNode* node = q.front();
            q.pop();

            int leftVal = getNextVal(i, data);
            int rightVal = getNextVal(i, data);

            if(leftVal != INT_MIN) {
                TreeNode* leftNode = new TreeNode(leftVal);
                node->left = leftNode;
                q.push(leftNode);
            }

            if(rightVal != INT_MIN) {
                TreeNode* rightNode = new TreeNode(rightVal);
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