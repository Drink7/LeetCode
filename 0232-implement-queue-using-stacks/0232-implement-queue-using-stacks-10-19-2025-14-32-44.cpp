class MyQueue {
public:
    MyQueue() {
        // two stacks
        // peek stack, when peek or pop, check empty or not, if empty, pop all elements from normal stack and then peek or pop
        // normal stack, all push num will push to this stk
        
    }
    
    void push(int x) {
        normalStk.push(x);
    }
    
    int pop() {
        if (peekStk.empty()) {
            while (normalStk.size() > 0) {
                peekStk.push(normalStk.top());
                normalStk.pop();
            }
        }
        int top = peekStk.top();
        peekStk.pop();
        return top;
    }
    
    int peek() {
        if (peekStk.empty()) {
            while (normalStk.size() > 0) {
                peekStk.push(normalStk.top());
                normalStk.pop();
            }
        }
        return peekStk.top();
    }
    
    bool empty() {
        return normalStk.empty() && peekStk.empty();
    }
private:
    stack<int> normalStk;
    stack<int> peekStk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */