class CustomStack {
public:
    CustomStack(int maxSize) {
        maxStackSize = maxSize;
    }
    
    void push(int x) {
        if (storage.size() < maxStackSize) {
            storage.push_back(x);
        }
    }
    
    int pop() {
        if (storage.empty()) {
            return -1;
        } else {
            int back = storage.back();
            storage.pop_back();
            return back;
        }
    }
    
    void increment(int k, int val) {
        int incrementLoop = storage.size() < k ? storage.size() : k;
        for (int i = 0; i < incrementLoop; i++) {
            storage[i] += val;
        }
    }
private:
    vector<int> storage;
    int maxStackSize = 0;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */