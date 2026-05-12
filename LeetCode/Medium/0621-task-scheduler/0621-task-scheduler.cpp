class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int interval = 0;
        priority_queue<int> available;
        queue<pair<int, int>> waiting;

        vector<int> count(26, 0);
        for(const auto& task : tasks) {
            count[task - 'A']++;
        }

        for(int i = 0; i < 26; i++) {
            if(count[i])  available.push(count[i]);
        }

        while(!available.empty() || !waiting.empty()) {
            interval++;

            while(!waiting.empty() && waiting.front().second <= interval) {
                available.push(waiting.front().first);
                waiting.pop();
            }

            if(!available.empty()) {
                if(available.top() > 1) waiting.push({available.top() - 1, interval + n + 1});
                available.pop();
            } else if(!waiting.empty()) {
                interval = max(interval, waiting.front().second - 1); //interval jump
            }
        }

        return interval;
    }
};