/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curr1 = headA, *curr2 = headB;
        bool curr1_shifted = false, curr2_shifted = false;

        while(curr1 != curr2) {
            curr1 = curr1->next;
            curr2 = curr2->next;

            if(curr1 == NULL) {
                if(curr1_shifted)  return NULL;
                curr1_shifted = true;
                curr1 = headB;
            }  
            if(curr2 == NULL) {
                if(curr2_shifted)  return NULL;
                curr2_shifted = true;
                curr2 = headA;
            }  
        }

        return curr1;
    }
};