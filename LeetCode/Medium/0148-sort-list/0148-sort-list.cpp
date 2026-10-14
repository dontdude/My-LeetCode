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
    ListNode* midFinder(ListNode* node) {
        if(node == nullptr) return nullptr;

        ListNode* slow = node, *fast = node->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right) {
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        while(left && right) {
            if(left->val < right->val) {
                prev->next = left;
                left = left->next;
                prev = prev->next;
            } else {
                prev->next = right;
                right = right->next;
                prev = prev->next;
            }
        }

        if(left)  prev->next = left;
        if(right) prev->next = right;

        return dummy->next;
    }

    ListNode* mergeSort(ListNode* node) {
        if(node == nullptr) return nullptr;
        if(node->next == nullptr) return node;

        ListNode* mid = midFinder(node);
        ListNode* node2 = mid->next;
        mid->next = nullptr;

        ListNode* left = mergeSort(node);
        ListNode* right = mergeSort(node2);

        return merge(left, right);
    }
public:
    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};