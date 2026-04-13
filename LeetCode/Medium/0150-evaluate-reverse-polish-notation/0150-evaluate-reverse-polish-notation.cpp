class Solution {
    char operators[4] = {'+', '-', '*', '/'};
    bool isOperator(string& token) {
        if(token.size() != 1)  return false;
        
        for(int k = 0; k < 4; k++) {
            if(token[0] == operators[k]) return true;
        }

        return false;
    }

    int tokenToNumber(string token) {
        if(token.size() < 1)  return 0;

        int sign = 1, num = 0;
        
        int i = 0;
        if(token[i] == '-') {
            sign = -1;
            i++;
        }

        while(i < token.size()) {
            int d = token[i] - '0';
            num *= 10;
            num += d;
            i++;
        }

        return sign * num;
    }

    int calculate(int num1, int num2, string sign) {
        if(sign[0] == '+')  return num1 + num2;
        if(sign[0] == '-')  return num1 - num2;
        if(sign[0] == '*')  return num1 * num2;
        if(sign[0] == '/')  return num1 / num2;
        return 0;
    }
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;

        for(string token : tokens) {
            int num;
            if(isOperator(token)) {
                if(operands.size() < 2)  return 0;

                int num2 = operands.top();
                operands.pop();

                int num1 = operands.top();
                operands.pop();

                num = calculate(num1, num2, token);
            } else {
                num = tokenToNumber(token);
            }

            operands.push(num);
        }

        return operands.top();
    }
};