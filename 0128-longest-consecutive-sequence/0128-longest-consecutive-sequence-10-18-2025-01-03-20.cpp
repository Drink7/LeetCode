class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // store into set
        // start from all start point, check longest
        // TC: O(n)
        // SC: O(n)
        unordered_set<int> dict;
        for (auto const& num : nums) {
            dict.insert(num);
        }

        int maxLen = 0;
        for (auto const& num : nums) {
            if (dict.count(num) < 1 || dict.count(num - 1) > 0) {
                continue;
            }

            int startNum = num;
            int len = 0;
            while (dict.count(startNum) > 0) {
                len++;
                dict.erase(startNum);
                startNum++;
            }
            maxLen = max(maxLen, len);
        }
        return maxLen;
    }
};