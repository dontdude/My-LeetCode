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
    Node* createCopyNodeOnEachNext(Node* head) {
        Node* curr = head;
        while(curr) {
            Node* copyOfCurr = new Node(curr->val);
            copyOfCurr->next = curr->next;
            curr->next = copyOfCurr;
            curr = copyOfCurr->next;
        }
        return head;
    }
    Node* assignRandomToCopyNode(Node* head) {
        Node* curr = head;
        while(curr) {
            Node* currRandom = curr->random;
            Node* currCopy = curr->next;
            if(currRandom) {     //some random node can be null
              currCopy->random = currRandom->next;
            } 
            curr = curr->next->next;
        }
        return head;
    }
    Node* breakCopyOutFromOriginalList(Node* head) {
        Node* original = head;
        Node* copyHead = new Node(-1), *copy = copyHead; //imp

        while(original && copy) {
            Node* originalNext = original->next->next;
            copy->next = original->next;
            original->next = originalNext;
            copy = copy->next;
            original = original->next;
        }
        return copyHead->next;
    }
    Node* copyRandomList(Node* head) {
        if(head == NULL) {
            return head;
        }
        
        head = createCopyNodeOnEachNext(head);
        head = assignRandomToCopyNode(head);
        Node* copyListHead = breakCopyOutFromOriginalList(head);
        return copyListHead;
    }
};