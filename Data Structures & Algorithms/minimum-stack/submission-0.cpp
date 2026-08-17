class MinStack {
public:
    vector<int> stack;
    MinStack() {
    }
    
    void push(int val) {
        stack.push_back(val);
        cout << val << endl;
    }
    
    void pop() {
        if (stack.size()!=0){
            stack.pop_back();
        }
    }
    
    int top() {
        if (stack.size()!=0){
            return stack.at(stack.size()-1);
        }
        else return 0;
    }
    
    int getMin() {
        int min = 0;
        if (stack.size()!=0){
            min = stack.at(0);
            for (int i = 0; i < stack.size(); i++){
                if (stack.at(i) < min) min = stack.at(i);
            }
        }
        return min;
    }
};
