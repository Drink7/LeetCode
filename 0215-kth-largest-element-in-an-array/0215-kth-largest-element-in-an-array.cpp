class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // MaxHeap Priority Queue
        // TC: O(nlogn + k)
        // SC: O(n)
        priority_queue<int> maxHeap;
        for (auto const& num : nums) {
            maxHeap.push(num);
        }

        int res = 0;
        for (int i = 0; i < k; i++) {
            res = maxHeap.top();
            maxHeap.pop();
        }
        return res;
    }
};