class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int left = 1, right = maxSum, res = 1;

        while(left <= right){
            int mid = left + (right - left) / 2;
            if(isPossible(mid, n, index, maxSum)){
                res = max(res, mid);
                left = mid + 1;
            }
            else right = mid - 1;
        }

        return res;
    }

    bool isPossible(int indMax, int n, int ind, int maxSum){
        long long sumTill = ((long long)indMax * (indMax - 1)) / 2;
        int posLeft = (indMax-1) - ind, posRight = (indMax-1) - (n - (ind+1));
        
        long long leftMinSum = sumTill, rightMinSum = sumTill;
        leftMinSum -= (posLeft > 0) ? (((long long)posLeft * (posLeft + 1)) / 2) : posLeft;
        rightMinSum -= (posRight > 0) ? (((long long)posRight * (posRight + 1)) / 2) : posRight;

        return maxSum >= leftMinSum + indMax + rightMinSum;
    }
};