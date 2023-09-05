class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        /*
        // Brute Force
        // TC: O(n)
        // SC: O(n)
        deque<int> dq;
        for (auto const& num : nums) {
            if (num % 2 == 0) {
                dq.push_front(num);
            } else {
                dq.push_back(num);
            }
        }
        
        vector<int> result;
        for (auto const& n : dq) {
            result.push_back(n);
        }
        return result;
        */

        // Two Pointer
        // similar to dutch national flag
        int left = 0;
        int right = nums.size() - 1;
        int cur = 0;
        while (left < right) {
            if (nums[cur] % 2 == 0) {
                left++;
                cur++;
            } else {
                swap(nums[cur], nums[right]);
                right--;
            }
        }
        return nums;
    }
};