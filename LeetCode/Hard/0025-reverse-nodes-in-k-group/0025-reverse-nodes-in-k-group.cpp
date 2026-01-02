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
    pair<ListNode*, ListNode*> reverse(ListNode* node, int k) {
        ListNode* prev = NULL;
        ListNode* curr = node;
        ListNode* next = NULL;

        while(k--) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        node->next = curr;
        return {prev, node};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL)  return head;

        ListNode* curr = head;

        int len = 0;
        while(curr) {
            len++;
            curr = curr->next;
        }


        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        curr = dummy;

        while(len >= k) {
            len -= k;
            pair<ListNode*, ListNode*> reversedGroup = reverse(curr->next, k);
            curr->next = reversedGroup.first;
            curr = reversedGroup.second;
        }

        return dummy->next;
    }
};