class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Sliding window basic
        // TC: O(n)
        // SC: O(1)
        int n = s.size();
        int left = 0;
        int right = 0;
        unordered_set<char> dict;
        int result = 0;

        while (right < n) {
            char cur = s[right];
            while (left <= right && dict.count(cur)) {
                dict.erase(s[left]);
                left++;
            }
            dict.insert(cur);
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};