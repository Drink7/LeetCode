class MinStack {
public:
    MinStack() {
        // two stack
        // one stack -> normal stack
        // one stack monotonic stack, store min value, only smaller than or equal than the top can store
    }
    
    void push(int val) {
        normalStack.push(val);
        if (monoStack.size() > 0 && val > monoStack.top()) {
            return;
        }
        monoStack.push(val);
    }
    
    void pop() {
        if (monoStack.size() > 0 && normalStack.size() > 0) {
            if (monoStack.top() == normalStack.top()) {
                monoStack.pop();
            }
        }
        normalStack.pop();
    }
    
    int top() {
        return normalStack.top();
    }
    
    int getMin() {
        return monoStack.top();
    }
private:
    stack<int> normalStack;
    stack<int> monoStack;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */