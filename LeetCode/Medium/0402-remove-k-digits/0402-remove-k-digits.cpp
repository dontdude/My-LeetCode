class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num == "0")  return "0";

        stack<char> st;
        int i = 0;
        string res = "";

        for(i = 0; i < num.size() && k > 0; i++) {
            while(k > 0 && (st.empty() == false && st.top() > num[i])) {
                k--;
                st.pop();
            }

            st.push(num[i]);
        }

        if(i != num.size()) {
            res = num.substr(i);
        }

        while(k > 0 && st.empty() == false) {
            st.pop();
            k--;
        }  

        string fromStack = "";
        while(st.empty() == false) {
            char c = st.top();
            st.pop();

            fromStack.push_back(c);   // instead of concatenate on single char.. using push_back.. it doesn't create new string in each concatenation, does no memory limit exceeded.
        }

        reverse(fromStack.begin(), fromStack.end());

        res = fromStack + res;

        i = 0;
        while(i < res.size() && res[i] == '0')  i++;

        if(i == res.size())   return "0";
        return res.substr(i); 
    }
};