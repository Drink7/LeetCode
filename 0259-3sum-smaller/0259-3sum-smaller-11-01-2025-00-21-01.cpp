class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // 3 sum concept
        // sort, check all valid triplet
        // duplicate is OK
        // TC: O(n^2)
        // SC: O(1)
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            int remain = target - nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right) {
                if (nums[left] + nums[right] < remain) {
                    cnt += right - left;
                    left++;
                } else {
                    right--;
                }
            }
        }
        return cnt;
    }
};