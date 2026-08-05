class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // use hash set, we don't care number counts
        // traverse the nums, only count if the num is the consecutive sequence's head
        // when counting, remove the num in set to avoid duplicate
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict(nums.begin(), nums.end());
        int result = 0;
        for (auto& num : nums) {
            if (dict.count(num - 1) < 1) {
                // is head, start counting
                int cur = num;
                int cnt = 0;
                while (dict.count(cur) > 0) {
                    dict.erase(cur);
                    cnt++;
                    cur++;
                }
                result = max(cnt, result);
            }
        }
        return result;
    }
};