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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = NULL, *curr = NULL;

        while(list1 && list2){
            if(list1->val <= list2->val){
               if(head == NULL)  head = list1;
               else curr->next = list1;

               curr = list1;
               list1 = list1->next;
            }
            else {
               if(head == NULL)  head = list2;
               else curr->next = list2;

               curr = list2;
               list2 = list2->next;
            }
        }

        if(list1){
            if(head == NULL)  head = list1;
            else curr->next = list1;
        }
        else {
            if(head == NULL)  head = list2;
            else curr->next = list2;
        }

        return head;
    }
};