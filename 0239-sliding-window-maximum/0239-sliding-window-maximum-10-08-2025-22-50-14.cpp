class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // deque -> maintain a monotonic queue, pop front and back
        // TC: O(n)
        // SC: O(n)
        deque<int> dq; // store index
        int n = nums.size();
        vector<int> result;
        int left = 0;
        int right = 0;
        while (right < n) {
            // insert into deque
            while (!dq.empty() && nums[dq.back()] < nums[right]) {
                dq.pop_back();
            }
            dq.push_back(right);

            if (right - left + 1 == k) {
                // insert the result (front)
                result.push_back(nums[dq.front()]);

                if (left == dq.front()) {
                    dq.pop_front();
                }
                left++;
            }
            right++;
        }
        return result;
    }
};