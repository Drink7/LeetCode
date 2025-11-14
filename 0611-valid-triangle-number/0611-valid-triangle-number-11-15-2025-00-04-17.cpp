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
        // TC: O(n)
        // SC: O(1)
        // sort, i, left, right
        // 2 2 3 3
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < nums.size(); j++) {
                int sum = nums[i] + nums[j];
                int k = j + 1;
                while (k < nums.size() && sum > nums[k]) {
                    cnt++;
                    k++;
                }
            }
        }
        return cnt;
    }
};