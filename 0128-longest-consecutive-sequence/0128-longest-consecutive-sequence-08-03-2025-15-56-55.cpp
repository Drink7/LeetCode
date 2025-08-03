class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // hash table -> unordered_set / unordered_map
        // find a number, check num++ / num-- exist or not
        // exist? check used or not
        // not exist, break;
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict(nums.begin(), nums.end());

        int result = 0;
        for (auto const& curVal : nums) {
            int nextVal = curVal + 1;
            int curLen = 1;
            dict.erase(curVal);

            while (dict.count(nextVal) > 0) {
                dict.erase(nextVal++);
                curLen++;
            }

            nextVal = curVal - 1;
            while (dict.count(nextVal) > 0) {
                dict.erase(nextVal--);
                curLen++;
            }
            result = max(result, curLen);
        }
        return result;
    }
};