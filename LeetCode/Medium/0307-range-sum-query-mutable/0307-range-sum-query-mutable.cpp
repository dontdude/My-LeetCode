class NumArray {
    int blockSize;
    vector<int> blocks;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        this->nums = nums;

        blockSize = sqrt(n) + 1;
        blocks.resize(blockSize, 0);

        for(int i = 0; i < n; i++) {
            blocks[i / blockSize] += nums[i];
        }
    }
    
    void update(int index, int val) {
        blocks[index / blockSize] += val - nums[index];
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        int startBlock = left / blockSize;
        int endBlock = right / blockSize;
        int sum = 0;

        if(startBlock == endBlock) {
            for(int i = left; i <= right; i++) sum += nums[i];
        } else {
            for(int i = left; i < (startBlock + 1) * blockSize; i++) sum += nums[i];

            for(int i = startBlock + 1; i < endBlock; i++)  sum += blocks[i];

            for(int i = endBlock * blockSize; i <= right; i++)  sum += nums[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */