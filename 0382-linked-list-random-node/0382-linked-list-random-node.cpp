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
    int n = 0;
    ListNode *Head = NULL;
    Solution(ListNode* head) {
        Head = head;
    }
    
    int getRandom() {
        ListNode *curr = Head;
        if(n == 0){
          while(curr){
            n++;
            curr = curr->next;
          }
          return Head->val;
        }

        int random = rand() % n;
        while(random--){
            curr = curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */