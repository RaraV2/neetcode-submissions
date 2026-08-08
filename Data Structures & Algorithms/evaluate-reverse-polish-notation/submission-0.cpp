class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> postfixStack;
        int operator1, operator2, result{}, tempRes;

        for (const auto& s : tokens) {
            if (s == "/" || s == "*" || s == "-" || s == "+") {
                operator2 = postfixStack.top();
                postfixStack.pop();
                operator1 = postfixStack.top();
                postfixStack.pop();
                if (s == "/") {
                    tempRes = operator1 / operator2;
                    postfixStack.push(tempRes);
                } else if (s == "*") {
                    tempRes = operator1 * operator2;
                    postfixStack.push(tempRes);
                } else if (s == "-") {
                    tempRes = operator1 - operator2;
                    postfixStack.push(tempRes);
                } else {
                    tempRes = operator1 + operator2;
                    postfixStack.push(tempRes);
                }
            }

            else {
                int integerS = stoi(s);
                postfixStack.push(integerS);
            }
        }

        return postfixStack.top();
    }
};
