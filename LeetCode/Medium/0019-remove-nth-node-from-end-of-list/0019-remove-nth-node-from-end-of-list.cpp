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
    int getLen(ListNode* node) {
        int len = 0;
        while(node) {
            len++;
            node = node->next;
        }

        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getLen(head);
        if(len <= 0 || len < n) return nullptr;
        if(len == n) return head->next;

        int target = len - n;
        ListNode* curr = head;

        while(target-- > 1) {
            curr = curr->next;
        }

        if(curr && curr->next) {
            curr->next = curr->next->next;
        }
        
        return head;
    }
};