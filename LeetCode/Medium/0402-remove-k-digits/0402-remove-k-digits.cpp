class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(n <= 1)  return "0";

        vector<char> stack;

        for(int i = 0; i < n; i++) {
            while((stack.size() > 0 && k > 0) && stack.back() > num[i]) {
                stack.pop_back();
                k--;
            }

            stack.push_back(num[i]);
        }

        while(stack.size() > 0 && k > 0) {
            stack.pop_back();
            k--;
        }

        string smallestNum = "";
        for(char digit : stack) {
            if(digit == '0' && smallestNum == "") {
                continue;
            }

            smallestNum.push_back(digit);
        }

        return smallestNum == "" ? "0" : smallestNum;
    }
};