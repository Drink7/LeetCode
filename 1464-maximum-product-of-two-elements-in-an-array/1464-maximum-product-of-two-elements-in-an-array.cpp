class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // sort the nums
        // pick the largest two
        // return their product
        // TC: O(nlogn)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};