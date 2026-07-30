class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(const char& task : tasks) {
            count[task - 'A']++;
        }

        priority_queue<int> available;
        for(int i = 0; i < 26; i++) {
            if(count[i]) available.push(count[i]);
        }

        int time = 0;
        queue<pair<int, int>> cooldown;

        while(!(available.empty() && cooldown.empty())) {
            while(!cooldown.empty() && cooldown.front().second <= time) {
                available.push(cooldown.front().first);
                cooldown.pop();
            }

            int task;
            if(available.empty()) {
                time = cooldown.front().second;
                task = cooldown.front().first;
                cooldown.pop();
            } else {
                task = available.top();
                available.pop();
            }

            if(task > 1) cooldown.push({task - 1, time + n + 1});
            time++;
        } 

        return time;
    }
};