class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // sort nums, find the third max
        // TC: O(nlogn)
        // SC: O(1)
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<>());
        int result = nums[0];
        int k = 2;
        for (int i = 1; i < n; i++) {
            while (i < n && nums[i] == nums[i - 1]) {
                i++;
            }

            if (i < n) {
                k--;
                result = nums[i];
                if (k == 0) break;
            }
        }
        return k == 0 ? result : nums[0];
    }
};