class MinStack {
private:
    stack<int> myStack;
    stack<pair<int, int>> minHistory;
    int currPos{};

public:
    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push(val);
        currPos = static_cast<int>(myStack.size() - 1);
        if(minHistory.empty()) minHistory.push({val,currPos});
        else if (minHistory.top().first == val) return;
        else if(minHistory.top().first > val) {
            minHistory.push({val,currPos});
        }
        else return;
    }
    
    void pop() {
        if(myStack.top() == minHistory.top().first &&
           currPos == minHistory.top().second){
            myStack.pop();
            minHistory.pop();
            --currPos;
            return;
        }
        myStack.pop();
        --currPos;
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minHistory.top().first;
    }
};
