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
    pair<ListNode*, ListNode*> reverse(ListNode* curr, int k) {
        ListNode *prev = NULL, *next = curr->next, *newLast = curr;
        while(k-- && curr) { 
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        newLast->next = next;     // connecting the new last with the next group
        return {prev, newLast};   // { head, last } of newly reversed 
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1) {
            return head;
        }

        int len = 0;
        ListNode* curr = head;
        while(curr) {
            curr = curr->next;
            len++;
        }

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prevGroup = dummy;

        while(len >= k) {
           auto curr = reverse(prevGroup->next, k);
           prevGroup->next = curr.first;

           prevGroup = curr.second;
           len -= k;
        }

        return dummy->next;
    }
};