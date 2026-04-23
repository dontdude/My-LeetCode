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
    ListNode* reverse(ListNode* node) {
        ListNode *prev = nullptr, *curr = node;

        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == nullptr)  return;

        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* revNode = reverse(slow->next);
        slow->next = nullptr;

        ListNode* node = head;
        while(node && revNode) {
            ListNode* next = node->next;
            ListNode* revNext = revNode->next;

            node->next = revNode;
            revNode->next = next;

            node = next;
            revNode = revNext;
        }

        return;
    }
};