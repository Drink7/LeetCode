class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // no need to sort first
        // Like house robber
        // #1 2 2 3 3 3 4 4
        // #2 if we steal 3, we can not steal 2 and 4, and the total earn will be the total count of 3 -> 9
        // #3 if we made the number store in an array -> 0 0 4 9 4
        // and apply the house robber concept!!
        // TC: O(nlogn)
        // SC: O(n)
        //sort(nums.begin(), nums.end());
        int maxElement = *max_element(nums.begin(), nums.end());
        vector<int> house(maxElement + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            house[nums[i]] += nums[i];
        }

        // house robber flow
        int n = house.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = house[0];
        for (int i = 2; i <= n; i++) {
            dp[i] = max(dp[i - 2] + house[i - 1], dp[i - 1]);
        }
        return dp[n];
    }
};