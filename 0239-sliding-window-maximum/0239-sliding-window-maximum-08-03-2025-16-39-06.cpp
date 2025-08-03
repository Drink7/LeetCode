class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque with sliding window
        // TC: O(n)
        // SC: O(n)
        deque<int> dq;
        int left = 0;
        int right = 0;
        int n = nums.size();
        vector<int> result;
        while (right < n) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }

            dq.push_back(right);
            // if left element out of bound
            // remove left 
            if (left > dq.front()) {
                dq.pop_front();
            }

            // store max val
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
                left++;
            }
            right++;
        }
        return result;
    }
};