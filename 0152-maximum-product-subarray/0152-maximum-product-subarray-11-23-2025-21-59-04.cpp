class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // max arr / min arr
        // if nums[i] < 0, swap max val and min val
        // record max product from max val
        // TC: O(n)
        // SC: O(n)
        int n = nums.size();
        vector<int> maxArr(n);
        vector<int> minArr(n);
        maxArr[0] = nums[0];
        minArr[0] = nums[0];
        int maxVal = maxArr[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] < 0) {
                maxArr[i] = max(nums[i], minArr[i - 1] * nums[i]);
                minArr[i] = min(nums[i], maxArr[i - 1] * nums[i]);
            } else {
                maxArr[i] = max(nums[i], maxArr[i - 1] * nums[i]);
                minArr[i] = min(nums[i], minArr[i - 1] * nums[i]);
            }
            maxVal = max(maxVal, maxArr[i]);
        }
        return maxVal;
    }
};