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
        ListNode *prev = NULL;
        ListNode *curr = node;
        ListNode *next = NULL;

        while(k-- && curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        node->next = curr;
        return {prev, node};  // head and last of new reversed group
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)  return head;

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
            auto reversedGroup = reverse(curr->next, k);
            curr->next = reversedGroup.first;
            curr = reversedGroup.second;

            len -= k;
        }

        return dummy->next;
    }
};