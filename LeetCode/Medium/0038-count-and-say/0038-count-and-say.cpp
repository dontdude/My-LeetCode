class Solution {
    string produceRLE(string& s) {
        string rle = "";
        int count = 1;
        char prev = s[0];

        for(int i = 1; i < s.size(); i++) {
            if(s[i] == prev) {
                count++;
            } else {
                rle.push_back('0' + count);
                rle.push_back(prev);

                prev = s[i];
                count = 1;
            }
        }

        rle.push_back('0' + count);
        rle.push_back(prev);

        return rle;
    }
public:
    string countAndSay(int n) {
        if(n == 1)  return "1";

        string rle = countAndSay(n - 1);

        return produceRLE(rle);
    }
};