/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        while(curr) {
            Node* copy_curr = new Node(curr->val);
            copy_curr->next = curr->next;
            curr->next = copy_curr;
            curr = copy_curr->next;
        }

        curr = head;
        while(curr) {
            if(curr->random != NULL)  curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        Node* dummy = new Node(-1);
        curr = head;
        Node* copy_prev = dummy;

        while(curr) {
            copy_prev->next = curr->next;
            curr->next = curr->next->next;
            
            copy_prev = copy_prev->next;
            curr = curr->next;
        }

        return dummy->next;
    }
};