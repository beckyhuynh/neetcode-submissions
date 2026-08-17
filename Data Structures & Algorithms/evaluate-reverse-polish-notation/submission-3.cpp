
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> rpn;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens.at(i) == "+" || tokens.at(i) == "-" || tokens.at(i) == "*" || tokens.at(i) == "/"){
                int first = 0;
                int second = 0;
                if (rpn.size()!=0){
                    second = rpn.top();
                    rpn.pop();
                    first = rpn.top();
                    rpn.pop();
                }

                if (tokens.at(i) == "+") {
                    rpn.push(first + second);
                }

                else if (tokens.at(i) == "-"){
                    rpn.push(first - second);
                }

                else if (tokens.at(i) == "*"){
                    rpn.push(first*second);
                }

                else if (tokens.at(i) == "/") {
                    rpn.push(first/second);
                }
            }

            else{
                rpn.push(stoi(tokens.at(i)));
            }
            
        }
        if(rpn.size()!= 0) return rpn.top();
        else return 0;
    }
};
