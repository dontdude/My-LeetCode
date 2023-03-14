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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head, *fast = head;

        // since fast moves with double speed of slow, therefore by the time, fast reaches the end of linkedlist, the slow would have reached the middle element
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        } 
        
        return slow;
    }
};