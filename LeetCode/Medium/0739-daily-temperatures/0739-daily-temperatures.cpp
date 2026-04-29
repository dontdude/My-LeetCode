class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        stack<int> mds; // want next greater
        vector<int> answer(n, 0);

        for(int i = n - 1; i >= 0; i--) {
            while(!mds.empty() && temperatures[mds.top()] <= temperatures[i]) {
                mds.pop();
            }

            if(!mds.empty())  answer[i] = mds.top() - i;

            mds.push(i);
        }

        return answer;
    }
};