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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> list;
    TreeNode* sortedListToBST(ListNode* head) {
        while(head){
            list.push_back(head->val);
            head = head->next;
        }
        return BST(0, list.size()-1);
    }
    TreeNode* BST(int l, int r){
        if(l >  r)  return NULL;

        int m = l + (r - l) / 2;
        TreeNode* curr = new TreeNode(list[m]);
        curr->left = BST(l, m - 1);
        curr->right = BST(m + 1, r);
        return curr;
    }
};