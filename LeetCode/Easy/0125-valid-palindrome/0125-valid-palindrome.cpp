class Solution {
    bool isAlphaNumberic(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9'); 
    }

    bool areEqual(char a, char b) {
        if(a == b) return true;
        if(('A' <= a && a <= 'Z') && b == (a - 'A') + 'a')  return true;
        if(('A' <= b && b <= 'Z') && a == (b - 'A') + 'a')  return true;
        
        return false;
    }
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size() - 1;

        while(left < right) { 
            if(!isAlphaNumberic(s[left])) {
                left++;
                continue;
            }

            if(!isAlphaNumberic(s[right])) {
                right--;
                continue;
            }

            if(!areEqual(s[left], s[right])) return false;

            left++;
            right--;
        }

        return true;
    }
};