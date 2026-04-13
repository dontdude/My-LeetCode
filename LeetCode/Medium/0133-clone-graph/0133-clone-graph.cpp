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
    Node* clone(unordered_map<int, Node*>& cloneHash, Node* node) {
        if(node == nullptr)  return nullptr;
        
        int val = node->val;
        if(cloneHash.find(val) != cloneHash.end()) {
            return cloneHash[val];
        }

        Node* cloneNode = new Node(val);
        cloneHash[val] = cloneNode;

        for(Node* nebr : node->neighbors) {
            cloneNode->neighbors.push_back(clone(cloneHash, nebr));
        }

        return cloneNode;
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> cloneHash;
        return clone(cloneHash, node);
    }
};