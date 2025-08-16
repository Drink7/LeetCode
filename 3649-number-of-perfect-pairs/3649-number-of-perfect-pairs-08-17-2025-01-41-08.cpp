class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        // sort, i < j, find j <= 2 * i
        for (auto& num : nums) {
            num = abs(num);
        }
        sort(nums.begin(), nums.end());

        int i = 0, j = 0;
        int n = nums.size();
        long long cnt = 0;
        for (; j < n; j++) {
            while (nums[i] * 2 < nums[j]) {
                i++;
            }
            cnt += j - i;
        }
        return cnt;
    }
};