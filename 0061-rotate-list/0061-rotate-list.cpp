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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)  return head;

        int n = 1;  
        ListNode* curr = head;
        while(curr->next)  curr = curr->next,  n++;
        curr->next = head;
        curr = head;


        k %= n;
        for(int i = 1; i < n - k; i++){
           curr = curr->next;
        }
        ListNode* newHead = curr->next;
        curr->next = NULL;

        return newHead;
    }
};