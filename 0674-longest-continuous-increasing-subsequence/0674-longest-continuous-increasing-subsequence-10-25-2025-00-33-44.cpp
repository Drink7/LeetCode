class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        // similar to Max Consecutive Ones
        // if strictly increasing, cnt++, calculate maximum
        // TC: O(n)
        // SC: O(1)
        int result = 1;
        int cnt = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                cnt++;
                result = max(result, cnt);
            } else {
                cnt = 1;
            }
        }
        return result;
    }
};