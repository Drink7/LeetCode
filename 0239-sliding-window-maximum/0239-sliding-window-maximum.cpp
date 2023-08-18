class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /*
        // Brute Force -> TLE
        // TC: O(nk)
        // SC: O(1)
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n - k + 1; i++) {
            int maxVal = INT_MIN;
            for (int j = 0; j < k; j++) {
                maxVal = max(maxVal, nums[i + j]);
            }
            result.push_back(maxVal);
        }
        return result;
        */

        // Sliding window with deque
        // push_back / push_front / pop_back / pop_front
        // we keep the deque front always the largest element
        // pop up the smaller element when there is a new element need to add to the tail of deque
        // TC: O(n)
        // SC: O(n)
        deque<int> dq;
        vector<int> result;
        int n = nums.size();
        int right = 0;
        while (right < n) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            // check if we need to pop front
            if (dq.front() == right - k) {
                dq.pop_front();
            }

            // start to store max val
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
            right++;
        }
        return result;
    }
};