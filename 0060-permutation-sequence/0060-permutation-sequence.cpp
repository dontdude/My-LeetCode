class Solution {
public:
    void dfs(int curr, int n, int k, vector<bool>& fixedNumbers, vector<int>& factorials, string& res) {
        if(curr == n) {
            return;
        }

        int ind = n - curr - 1;
        int permutWithCur = factorials[ind];
        int curPos = (k - 1) / permutWithCur;      // pos of number to include now
        int leftK = k - (curPos * permutWithCur);  // left counts

        int choosen = 0;
        for(int i = 1; i <= n; i++) {
            if(fixedNumbers[i] == false && curPos <= 0) {
                choosen = i;
                fixedNumbers[i] = true;
                break;
            } else if(fixedNumbers[i] == false) {
                curPos--;
            }
        }

        res += to_string(choosen);
        dfs(curr + 1, n, leftK, fixedNumbers, factorials, res);
    }

    string getPermutation(int n, int k) {
        vector<bool> fixedNumbers(n + 1, false);
        vector<int> factorials(n + 1, 1);
        for(int i = 1; i <= n; i++) {
            factorials[i] = (i * factorials[i-1]);
        }

        string res = "";
        dfs(0, n, k, fixedNumbers, factorials, res);
        return res;
    }
};