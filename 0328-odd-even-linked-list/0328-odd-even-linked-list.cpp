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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *dummy1 = new ListNode(-1, head), *dummy2 = new ListNode(-1);
        ListNode *prv1 = dummy1, *prv2 = dummy2, *curr = head;
        int p = 1;
        
        while(curr) {
            if(p) {
                prv1->next = curr;
                prv1 = prv1->next;
            } else {
                prv2->next = curr;
                prv2 = prv2->next;
            }
            p ^= 1;
            curr = curr->next;
        }
        prv2->next = NULL;
        prv1->next = dummy2->next;

        return dummy1->next;
    }
};