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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>> maxheap;

        for(const auto& list : lists) {
            if(list) maxheap.push({-list->val, list});
        }

        ListNode *dummy = new ListNode(); 
        ListNode *curr = dummy;

        while(!maxheap.empty()) {
            ListNode* node = maxheap.top().second;
            maxheap.pop();

            curr->next = node;
            curr = curr->next;

            if(node->next) maxheap.push({-node->next->val, node->next});
        }

        return dummy->next;
    }
};