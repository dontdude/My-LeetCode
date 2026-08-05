class KthLargest {
    private class TreeNode {
        int val;
        int count;  // duplicated val nodes
        int subtreeSize;  // size of subtree, including duplicate nodes
        TreeNode left;
        TreeNode right;

        public TreeNode(int val) {
            this.val = val;
            this.count = 1;
            this.subtreeSize = 1;
            left = null;
            right = null;
        }
    }

    private TreeNode root;
    private int k;

    private TreeNode addNum(TreeNode node, int num) {
        if(node == null) {
            return new TreeNode(num);
        }

        if(node.val == num) {
            node.count++;
        } else if(node.val > num) {
            node.left = addNum(node.left, num);
        } else {
            node.right = addNum(node.right, num);
        }

        node.subtreeSize++;
        return node;
    }

    private int getKth(TreeNode node, int k) {
        if(node == null) return -1;

        int rightCount = (node.right == null) ? 0 : node.right.subtreeSize;

        if(k <= rightCount) {
            return getKth(node.right, k);
        }

        int rightCountPlusCurr = rightCount + node.count;
        if(k <= rightCountPlusCurr) {
            return node.val;
        }

        return getKth(node.left, k - rightCountPlusCurr);
    }

    public KthLargest(int k, int[] nums) {
        this.k = k;
        this.root = null;

        for(int i = 0; i < nums.length; i++) {
            this.root = addNum(this.root, nums[i]);
        }
    }
    
    public int add(int val) {
        this.root = addNum(this.root, val);
        return getKth(this.root, this.k);
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */