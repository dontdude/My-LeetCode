/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int maxSum;
    private static class SubtreeInfo {
        public boolean isBST;
        public int minVal;
        public int maxVal;
        public int sum;

        public SubtreeInfo(boolean isBST, int minVal, int maxVal, int sum) {
            this.isBST = isBST;
            this.minVal = minVal;
            this.maxVal = maxVal;
            this.sum = sum;
        }
    }

    private SubtreeInfo dfs(TreeNode node) {
        if(node == null) return new SubtreeInfo(true, Integer.MAX_VALUE, Integer.MIN_VALUE, 0);

        SubtreeInfo left = dfs(node.left);
        SubtreeInfo right = dfs(node.right);

        if((left.isBST && right.isBST) && (left.maxVal < node.val && right.minVal > node.val)) {
            int sum = node.val + left.sum + right.sum;
            int currMin = Math.min(node.val, left.minVal);
            int currMax = Math.max(node.val, right.maxVal);

            maxSum = Math.max(maxSum, sum);
            return new SubtreeInfo(true, currMin, currMax, sum);
        }

        return new SubtreeInfo(false, 0, 0, 0);
    }

    public int maxSumBST(TreeNode root) {
        maxSum = 0;
        dfs(root);
        return maxSum;
    }
}