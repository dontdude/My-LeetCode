class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(const int& task : tasks) count[task - 'A']++;

        priority_queue<int> available;
        queue<pair<int, int>> waiting;
        int time = 0;

        for(int i = 0; i < 26; i++) {
            if(count[i]) available.push(count[i]);
        }

        while(!waiting.empty() || !available.empty()) { 
            while(!waiting.empty() && waiting.front().first <= time) {
                available.push(waiting.front().second);
                waiting.pop();
            }

            if(!available.empty()) {
                int curCount = available.top();
                available.pop();

                int nextTime = time + (n + 1);
                if(curCount > 1) waiting.push({nextTime, curCount - 1});
                time++;
            } else if(!waiting.empty()) {
                time = waiting.front().first;
            }
        }

        return time;
    }
};