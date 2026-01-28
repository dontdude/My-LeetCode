class Solution {
public:
    int applyOperation(int n1, int n2, string op) {
        switch (op[0]) {
            case '+': return n2 + n1;
            case '-': return n2 - n1;
            case '*': return n2 * n1;
            case '/': return n2 / n1;
        }

        return 0;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        vector<string> operators = {"+", "-", "*", "/"};

        for(string token: tokens) {
            if(token == "+" || token == "-" || token == "*" || token == "/") {
                int number1 = st.top();  
                st.pop();

                int number2 = st.top();
                st.pop();

                int number3 = applyOperation(number1, number2, token);
                st.push(number3); 
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};