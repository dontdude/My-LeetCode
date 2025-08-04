/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class BSTIterator {
private:
    stack<TreeNode*> myStack;
    bool isReverse;

    void pushSideNodes(TreeNode* node) {
        while (node) {
            myStack.push(node);
            node = isReverse ? node->right : node->left;
        }
    }

public:
    BSTIterator(TreeNode* node, bool reverse) {
        isReverse = reverse;
        pushSideNodes(node);
    }

    bool hasNext() { return !myStack.empty(); }

    int next() {
        TreeNode* curr = myStack.top();
        myStack.pop();

        if (isReverse) {
            pushSideNodes(curr->left);
        } else {
            pushSideNodes(curr->right);
        }

        return curr->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL)
            return false;

        BSTIterator left_iterator(root, false);
        BSTIterator right_iterator(root, true);

        // similar to finding the sum pair in a sorted list using two pointers
        int left = left_iterator.next();
        int right = right_iterator.next();

        while (left < right) {
            int pairSum = left + right;

            if (pairSum == k) {
                return true;
            } else if (pairSum < k) {
                left = left_iterator.next();
            } else {
                right = right_iterator.next();
            }
        }

        return false;
    }
};