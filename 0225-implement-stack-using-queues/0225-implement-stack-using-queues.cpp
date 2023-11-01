class MyStack {
public:
    MyStack() {
        
    }
    
    void push(int x) {
        popQueue.push(x);

        if (popQueue.size() > 1) {
            holdQueue.push(popQueue.front());
            popQueue.pop();
        }
    }
    
    int pop() {
        int val = popQueue.front();
        popQueue.pop();

        // loop the hold queue
        int holdQueueSize = holdQueue.size();
        for (int i = 0; i < holdQueueSize; i++) {
            push(holdQueue.front());
            holdQueue.pop();
        }

        return val;
    }
    
    int top() {
        return popQueue.front();
    }

    bool empty() {
        if (popQueue.empty() && holdQueue.empty()) {
            return true;
        } else {
            return false;
        }
    }

private:
    queue<int> popQueue;
    queue<int> holdQueue;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */