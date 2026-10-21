class Solution {
    // rec(o, c)  // o = n -> 0 & c = n -> 0
    //     if(c == 0)  return res.push_back(curr)

    //     if(o > 0)  {
    //         curr.push_back("(")
    //         rec(o - 1, c)
    //     } 
    //     curr.pop_back()

    //     if(o < c) {
    //         curr.push_back(")")
    //         rec(o, c - 1)
    //     }
    //     curr.pop_back()


    vector<string> result;
    void backtracking(int o, int c, string& curr) {
        if(c == 0) {
            if(o == 0)  result.push_back(curr);
            return;
        }

        if(o > 0) {
            curr.push_back('(');
            backtracking(o - 1, c, curr);
            curr.pop_back();
        }

        if(o < c) {
            curr.push_back(')');
            backtracking(o, c - 1, curr);
            curr.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string curr = "";
        backtracking(n, n, curr);
        return result;
    }
};