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
class Compare {                           // comparator class
public:
    bool operator()(ListNode* l1, ListNode* l2){          
        return l1->val >= l2->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for(auto list : lists)  if(list != NULL)  pq.push(list);

        ListNode *head = NULL, *tail = NULL;
        while(!pq.empty()){
            auto curr = pq.top();    pq.pop();
            if(curr->next != NULL)  pq.push(curr->next);

            if(!head)  head = tail = curr;
            else {
                tail->next = curr;
                tail = tail->next;
            }
        }

        return head;
    }
};