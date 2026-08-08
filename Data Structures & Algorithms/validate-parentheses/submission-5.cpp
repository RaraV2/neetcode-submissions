char equivalentBracket(char&);

class Solution {
   public:
    bool isValid(string s) {
        stack<char> m;
        int i{}, arrSize{static_cast<int>(s.length())};

        for (i = 0; i < arrSize; ++i) {
            if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
                if (m.empty()) return false;
                else if ( m.top() == equivalentBracket(s[i]) ){
                    m.pop();
                }
                else return false;
            }

            else m.push(s[i]);
        }

        if(m.empty()) return true;
        else return false;
    }
};

char equivalentBracket(char& c) {
    if (c == ')')
        return '(';
    else if (c == '}')
        return '{';
    else if (c == ']')
        return '[';
    else
        return c;
}
