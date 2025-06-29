class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // k large -> heap
        // Min Heap but keep nums.size - k + 1
        // TC: O(n * log (n - k + 1))
        // SC: O(k)
        priority_queue<int> minHeap;

        for (auto const& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > nums.size() - k + 1) {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};