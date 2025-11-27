class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // find k largest -> k minheap
        // TC: O(nlogk)
        // SC: O(k)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (auto const& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};