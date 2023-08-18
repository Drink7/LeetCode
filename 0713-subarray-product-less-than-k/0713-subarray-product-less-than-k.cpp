class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        /*
        // Brute force for loop (TLE)
        // TC: O(n^2)
        // SC: O(1)
        int result = 0;
        for (int left = 0; left < nums.size(); left++) {
            long leftNum = nums[left];
            if (leftNum < k) {
                result++;
                for (int right = left + 1; right < nums.size(); right++) {
                    leftNum = leftNum * nums[right];
                    if (leftNum < k) {
                        result++;
                    } else {
                        break;
                    }
                }
            }
        }
        return result;
        */

        // Sliding window
        // if product strictly less than k, it is our answer
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = 0;
        int n = nums.size();
        int base = 1;
        int result = 0;
        while (right < n) {
            base = base * nums[right];
            while (left <= right && base >= k) {
                base = base / nums[left];
                left++;
            }
            result += right - left + 1;
            right++;
        }
        return result;
    }
};