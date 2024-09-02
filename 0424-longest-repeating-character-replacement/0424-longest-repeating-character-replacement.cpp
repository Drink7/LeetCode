class Solution {
public:
    int characterReplacement(string s, int k) {
        // longest, substring -> sliding window
        // check max freq
        // right - left + 1 - max freq <= k
        // TC: O(26 * n)
        // SC: O(n)
        vector<int> charDict(26, 0);
        int right = 0;
        int left = 0;
        int result = 0;
        while (right < s.size()) {
            charDict[s[right] - 'A']++;
            while (right - left + 1 - findMax(charDict) > k) {
                charDict[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }

    int findMax(vector<int>& nums) {
        int result = 0;
        for (auto const& num : nums) {
            if (num > result) {
                result = num;
            }
        }
        return result;
    }
};