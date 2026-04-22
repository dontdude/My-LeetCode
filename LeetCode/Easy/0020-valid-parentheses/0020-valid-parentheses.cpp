class Solution {
    string openingBrackets = "({[";
    string closingBrackets = ")}]";
    bool isOpening(char bracket) {
        for(char ob : openingBrackets) {
            if(ob == bracket) return true;
        }

        return false;
    }

    bool isPair(char opening, char closing) {
        for(int i = 0; i < 3; i++) {
            if(opening == openingBrackets[i]) {
                return closing == closingBrackets[i];
            }
        }

        return false;
    }
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s) { 
            if(isOpening(c)) {
                st.push(c);
            } else if(!st.empty() && isPair(st.top(), c)) {
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};