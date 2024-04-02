class Solution {
public:
    int specialArray(vector<int>& nums) {
        // nums is special: there are exactly x numbers in nums that are greater than or equal to x.
        // find the value between 1 to nums.size()
        // find the first value >= x
        // Binary search
        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int low = 0;
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int cnt = nums.size() - mid;
            if (nums[mid] >= cnt) {
                if (mid == 0 || nums[mid - 1] < cnt) {
                    return cnt;
                } else {
                    high = mid - 1;
                }
            } else {
                low = mid + 1;
            }
        }
        return -1;
    }
};