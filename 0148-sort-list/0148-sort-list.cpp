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
    ListNode* sortList(ListNode* head) {
        if(head == NULL)  return head;
        return mergeSort(head);
    }

    ListNode* mergeSort(ListNode* head){
        if(!head->next)  return head;
        
        ListNode* mid = midFinder(head);
        
        ListNode* right = mergeSort(mid->next);
        mid->next = NULL;
        ListNode* left = mergeSort(head);

        return merge(left, right);
    }

    ListNode* merge(ListNode* left, ListNode* right){
        ListNode *dummy = new ListNode(), *curr = dummy;

        while(left && right){
           if(left->val < right->val)  curr->next = left,  left = left->next;
           else curr->next = right,  right = right->next;

           curr = curr->next;
        }
        if(left)   curr->next = left;
        if(right)  curr->next = right;

        return dummy->next;
    }

    ListNode* midFinder(ListNode* head){
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        return slow;
    }
};