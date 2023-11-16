class Solution {
public:
    string reorganizeString(string s) {
        string res = "";
        int n = s.size();
        map<char, int> freq;

        char mxCh = ' ';
        for(auto ch : s) {
            freq[ch]++;
            if(mxCh == ' ' || freq[mxCh] < freq[ch]){
                mxCh = ch;
            }
        }
 
        int mxfrq = freq[mxCh], rest = n - mxfrq;
        if(rest < mxfrq - 1)  return res;
       
       freq.erase(mxCh);
        while(rest || mxfrq) {
            if(mxfrq) res += mxCh;
            mxfrq--;

            if(rest <= 0)  break;
            for(auto & c: freq) {
                if(rest >= mxfrq) {
                    res += c.first;
                    c.second--;
                    rest--;
                    
                    if(c.second == 0)  freq.erase(c.first);
                }
            }
        }

        return res;
    }
};