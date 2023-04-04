class Solution {
public:
    // Nice bitwise method to not use set, 0th position bit will represent whether a is present or not 
    bool checkBit(int bits, int n){
        return (bits & (1 << n));
    }
    void setBit(int& bits, int n){ 
        bits |= (1 << n);  
    }

    int partitionString(string s) {
        int res = 1, bits = 0;
        for(auto c : s){
            int n = c - 'a';
            if(checkBit(bits, n)){ 
                bits = 0;
                res++;
            }
            setBit(bits, n); 
        }
        return res;
    }
};