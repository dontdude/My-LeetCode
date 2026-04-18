class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if(n % groupSize != 0)  return false;

        map<int, int> count;
        for(int i = 0; i < n; i++)  count[hand[i]]++;

        int times = n / groupSize;
        while(times--) {
            int s = groupSize;
            int curr = count.begin()->first;

            while(s--) {
                if(count.find(curr) == count.end()) {
                    return false;
                }

                if(--count[curr] == 0)  count.erase(curr);
                curr++;
            }
        }

        return true;
    }
};