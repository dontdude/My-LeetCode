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
public:
    Node* cloneGraph(Node* node) {
       if(!node)  return NULL;
       unordered_map<Node*, Node*> vis;
       queue<Node*> q;
       
       return cloner(node, vis); 
    }

    Node* cloner(Node* node, unordered_map<Node*, Node*>& vis){
       Node* clone = new Node(node->val, node->neighbors);
       vis.insert({node, clone});

       for(int i = 0; i < node->neighbors.size(); i++) {
          if(node->neighbors[i]){ 
            if(vis.find(node->neighbors[i]) == vis.end())   clone->neighbors[i] = cloner(node->neighbors[i], vis);
            else clone->neighbors[i] = vis[node->neighbors[i]];
          }
       }
       
       return clone;
    }
};