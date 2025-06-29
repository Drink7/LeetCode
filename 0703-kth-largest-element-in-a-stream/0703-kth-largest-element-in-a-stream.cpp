class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        // k large -> heap
        // keep minHeap to k size
        // TC: O(nlogn)
        // SC: O(n)
        kth = k;
        int n = nums.size();
        for (auto const& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        if (minHeap.size() > kth) {
            minHeap.pop();
        }
        return minHeap.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int kth = 0;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */