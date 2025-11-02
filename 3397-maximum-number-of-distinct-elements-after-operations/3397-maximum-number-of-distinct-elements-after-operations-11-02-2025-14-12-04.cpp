class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        // sort
        // from the first, add the minimum (-k) and find if exist
        // TC: O(k * nums.size()) -> TLE

        sort(nums.begin(), nums.end());
        int ans = 0;
        int prev = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            int l = max(nums[i] - k, prev + 1);
            l = min(l, nums[i] + k);
            if (l > prev) {
                prev = l;
                ans++;
            }
        }
        return ans;
    }
};