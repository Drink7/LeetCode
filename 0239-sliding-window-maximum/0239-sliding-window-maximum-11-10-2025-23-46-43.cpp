class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // push from back
        // pop front, back with monotonic queue (decreasing)
        // #1 init a deque, push num into deque
        // if deque is empty, just push_back
        // if deque is not empty, compare, if deque back < incoming, pop_back
        // #2 right keep going, when right - left + 1 == k
        // #3 front is the max
        // #4 left >= front index, pop_front, left++
        // until right < n
        // TC: O(n)
        // SC: O(n)
        deque<int> dq;
        vector<int> result;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while (right < n) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            if (right - left + 1 == k) {
                result.push_back(nums[dq.front()]);
                if (left >= dq.front()) {
                    dq.pop_front();
                }
                left++;
            }
            right++;
        }
        return result;
    }
};