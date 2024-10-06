class SmallestInfiniteSet {
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1001; i++) {
            pq.push(i);
            dict[i] = true;
        }
    }
    
    int popSmallest() {
        int top = pq.top();
        pq.pop();
        dict[top] = false;
        return top;
    }
    
    void addBack(int num) {
        if (dict[num]) {
            return;
        }
        pq.push(num);
        dict[num] = true;
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    unordered_map<int, bool> dict;
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */