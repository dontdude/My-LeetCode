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
struct compareByVal{
    bool operator()(ListNode* node1, ListNode* node2) {
        return node1->val > node2->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compareByVal> pq;

        for(ListNode* list : lists) {
            if(list != NULL) {
                pq.push(list);
            }     
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;

        while(pq.empty() == false) {
            ListNode* curr = pq.top();
            pq.pop();

            prev->next = curr;
            prev = curr;

            if(curr->next) {
                pq.push(curr->next);
            }
        }

        return dummy->next;
    }
};