/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* dfs(Node* node, unordered_map<Node*, Node*>& nodeHash) {
        if(node == NULL) {
            return NULL;
        }

        // Node already exsist
        if(nodeHash.find(node) != nodeHash.end()) {
            return nodeHash[node];
        }

        // Else, creating new node.. and stroing it in hash 
        Node* copyNode = new Node(node->val);
        nodeHash[node] = copyNode;

        // Adding cloned nebr graph
        for(Node* nebr : node->neighbors) {
            Node* copyNebr = dfs(nebr, nodeHash);
            copyNode->neighbors.push_back(copyNebr);
        }

        return copyNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> nodeHash;
        return dfs(node, nodeHash);
    }
};