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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *Prev = NULL;
        while(fast && fast->next){
            fast = fast->next->next;  // make this move first

            ListNode* Next = slow->next;
            slow->next = Prev;
            Prev = slow;
            slow = Next;    // Jumping slow by 1, but also reversing linked list
        }

        if(fast)  slow = slow->next;  // slow will now point to first element of second palindrome half
        // and Prev is pointing to first element of first palindrome half (as now reversed) 

        while(slow && Prev){
            if(slow->val != Prev->val)  return false;
            slow = slow->next;
            Prev = Prev->next;
        }

        return !(slow || Prev);
    }
};