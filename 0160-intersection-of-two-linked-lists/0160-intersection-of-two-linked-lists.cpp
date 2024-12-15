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
        ListNode *p1 = headA, *p2 = headB;

        while(p1->next)   p1 = p1->next;
        while(p2->next)   p2 = p2->next;
        
        if(p1->val != p2->val) {
            return NULL;
        }

        p1 = headA, p2 = headB;
        while(p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;

            // After one entire circle in both the list, the number of visited node by both pointer would become same.
            if(!p1)  p1 = headA;
            if(!p2)  p2 = headB;
        }

        return p1;
    }
};