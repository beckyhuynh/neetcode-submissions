class Solution {
public:
    bool isValid(string s) {
        stack <char> brackets;
        brackets.push(s[0]);
        // cout << s.length() << endl;
        for (int i = 1; i < s.length(); i++){
            if (!brackets.empty()) {
                if (s[i] == '}' && brackets.top() == '{'){
                    brackets.pop();
                    cout << "{}" <<endl;
                }
                else if (s[i] == ']' && brackets.top() == '['){
                    cout << "[]" <<endl;
                    brackets.pop();
                }
                else if (s[i] == ')' && brackets.top() == '('){
                    // cout << "()" <<endl;
                    brackets.pop();
                    
                }
                else brackets.push(s[i]);
                cout << brackets.size() << endl;
            }
            else brackets.push(s[i]);
        }
        cout << brackets.size();
        if (brackets.size()!= 0) return false;
        return true;
    }
};
