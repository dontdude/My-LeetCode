/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    
    Node* flattenedTail(Node* curr) {
        while(curr) {
            Node* next = curr->next;

            if(curr->child != NULL) {
                Node* childTail = flattenedTail(curr->child);

                curr->next = curr->child;
                curr->child->prev = curr;
                
                if(next != NULL) next->prev = childTail;
                childTail->next = next;

                curr->child = NULL;
                curr = childTail;
            }

            if(next == NULL) break;
            curr = next;
        }

        return curr;
    }
    Node* flatten(Node* head) {
        Node* curr = head;
        while(curr) {
            if(curr->child != NULL) {
                curr = flattenedTail(curr);
            } else {
                curr = curr->next;
            }
        }

        return head;
    }
};