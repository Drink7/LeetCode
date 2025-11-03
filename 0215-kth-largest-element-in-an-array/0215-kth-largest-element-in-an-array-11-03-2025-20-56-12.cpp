class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // k large -> min Heap with k
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