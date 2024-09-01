class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // substring, longest -> sliding window
        // sliding window
        // TC: O(n)
        // SC: O(n)
        int left = 0;
        int right = 0;
        int result = 0;
        unordered_set<char> dict;
        while (right < s.size()) {
            char c = s[right];
            while (dict.count(c) > 0) {
                dict.erase(s[left]);
                left++;
            }
            dict.insert(c);
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};