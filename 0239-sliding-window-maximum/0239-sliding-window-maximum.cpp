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
        // Maintain sliding window
        // TC: O(n)
        // SC: O(k)
        deque<int> dq;
        vector<int> result;
        int n = nums.size();
        int right = 0;
        while (right < n) {
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);
            if (dq.front() == right - k) {
                dq.pop_front();
            }
            if (right >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
            right++;
        }
        return result;
    }
};