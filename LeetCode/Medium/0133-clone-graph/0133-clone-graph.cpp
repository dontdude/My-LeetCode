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
    Node* dfs(Node* node, unordered_map<Node*, Node*>& cloneMap) {
        if(cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        } 

        Node* clonedNode = new Node(node->val); 
        cloneMap[node] = clonedNode;

        for(Node* nebr : node->neighbors) {
            clonedNode->neighbors.push_back(dfs(nebr, cloneMap));
        }

        return clonedNode;
    }
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr)  return nullptr;
        unordered_map<Node*, Node*> cloneMap;
        return dfs(node, cloneMap);
    }
};