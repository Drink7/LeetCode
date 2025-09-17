class MinStack {
public:
    MinStack() {
        // two stack
        // one stack is normal stack
        // the other stack will compare minStack top and cur
        // if minStack top is smaller, push again
        // or push cur
        // TC: O(n)
        // SC: O(n)
    }
    
    void push(int val) {
        normalStack.push(val);
        if (minStack.empty()) {
            minStack.push(val);
        } else {
            if (minStack.top() < val) {
                minStack.push(minStack.top());
            } else {
                minStack.push(val);
            }
        }
    }
    
    void pop() {
        normalStack.pop();
        minStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
private:
    stack<int> normalStack;
    stack<int> minStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */