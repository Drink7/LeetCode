class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // a + b > c -> triangle
        // c is the longest edge
        // sort reversely, so the longest will be the first
        // check how many pairs sum > longest edge
        // then to the 2nd longest edge
        // TC: O(n^2)
        // SC: O(1)
        int cnt = 0;
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
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