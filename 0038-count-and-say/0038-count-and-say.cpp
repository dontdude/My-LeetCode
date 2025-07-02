class Solution {
public:
    string countAndSay(int n) {
        if(n == 1)  return "1";

        string recs = countAndSay(n - 1);
        
        string cur = "";
        char ch = recs[0];
        int count = 1;
        for(int i = 1; i < recs.size(); i++) {
           if(ch == recs[i]) {
              count++;
           } else {
             cur += to_string(count) + ch;
             count = 1;
             ch = recs[i];
           }
        } 
        cur += to_string(count) + ch;

        return cur;
    }
};