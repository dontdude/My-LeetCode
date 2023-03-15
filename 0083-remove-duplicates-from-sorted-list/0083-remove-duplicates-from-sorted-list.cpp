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
    ListNode* deleteDuplicates(ListNode* head) {
        // move fast ahead if slow.val == fast.val
        // else set slow.next = fast && update slow = fast
        // i.e, slow will only hope to next unique node, while fast will hope to every node
        
        if(!head)  return head;

        auto slow = head, fast = head->next; 
        while(fast){
            if(fast->val == slow->val)   fast = fast->next;
            else {
                slow->next = fast;
                slow = fast;
                fast = fast->next;
            }
        } 
        slow->next = NULL;   // to mark that this unique element is last node

        return head;
    }
};