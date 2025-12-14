class Solution {
public:
    char charAtDistance(char c, int distance) {
        if((int)c - distance <= (int)'a')  return 'a';
        if((int)c + distance > (int)'z')  return 'a';

        return (char)c - distance;
    }

    string getSmallestString(string s, int k) {
        int i = 0;
        string res = s;

        while(k > 0 && i < s.size()) {
            char curr = charAtDistance(s[i], k);

            int takenGap = min(abs(s[i] - curr), 'z' - s[i] + curr - 'a' + 1);
            k -= takenGap;

            res[i] = curr;
            i++;
        }
       
        return res;
    }
};