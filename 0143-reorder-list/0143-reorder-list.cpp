/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        
        // Finding middle node
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // Reversing 2nd half of linked list
        fast = slow->next;
        slow->next = NULL;
        slow = NULL;        // slow act as prev node, and fast as curr node
        while(fast){
           ListNode* Next = fast->next;
           fast->next = slow;
           slow = fast;
           fast = Next;
        }

        // Combining two list, slow will be the head of rotated half;
        while(head && slow){
            ListNode *Next1 = head->next, *Next2 = slow->next;
            head->next = slow;   
            slow->next = Next1;
            head = Next1;
            slow = Next2;
        }
    }
};