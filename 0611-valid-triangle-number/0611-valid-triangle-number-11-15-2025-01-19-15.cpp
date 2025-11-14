class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        // a + b > c
        // cnt += c - b
        // a + b <= c
        // move b
        // find if a + b > c
        // cnt += c - b
        // move c
        // find if a + b > c
        // cnt += c - b
        // TC: O(n^3)
        // SC: O(1)
        // sort, i, left, right
        // 2 2 3 3
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = nums.size() - 1; i >= 0 ; i--) {
            int left = 0;
            int right = i - 1;
            while (left < right) {
                if (nums[left] + nums[right] > nums[i]) {
                    // i + left > right --> i + left + 1 > right
                    // count += right - left
                    cnt += right - left;
                    right--;
                } else {
                    // <=
                    left++;
                }
            }
        }
        return cnt;
    }
};