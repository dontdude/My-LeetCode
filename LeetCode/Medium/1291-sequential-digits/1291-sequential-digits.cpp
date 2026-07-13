class Solution {
    vector<int> sequentialDigitList;

    void prepareSequentialDigitList() {
        int d = 1, end = 1e9;

        while(d < 9) {
            int curr = d * 10 + (d + 1);
            sequentialDigitList.push_back(curr);
            d++;
        }

        int n = sequentialDigitList.size() - 1;
        int m = n;

        while(m >= 0 && sequentialDigitList.back() < end) {
            int num = sequentialDigitList[n - m];
            int lastD = num % 10;
            if(lastD == 9)  {  
                m--;
                continue;
            }

            int newNum = (num * 10) + (lastD + 1);
            sequentialDigitList.push_back(newNum);
            n++;
        }
    }
public:
    Solution() {
        prepareSequentialDigitList();
    }
    vector<int> sequentialDigits(int low, int high) {
        auto lowIt = lower_bound(sequentialDigitList.begin(), sequentialDigitList.end(), low);
        auto highIt = upper_bound(sequentialDigitList.begin(), sequentialDigitList.end(), high);

        vector<int> result(lowIt, highIt);
        return result;
    }
};