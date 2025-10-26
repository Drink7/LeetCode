class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // right keep going
        // use hash set for checking repeat
        // if s[right] is existed in hash set, move the left until s[right] is not existed
        // check the longest substring
        // TC: O(n), n is s.size()
        // SC: O(1)
        // s = ""
        // s = "abcabcbb"
        // hash set: a, b, c
        // n = 8
        // left:5, right = 8
        // c = b
        // result = 3
        int left = 0, right = 0;
        unordered_set<int> dict;
        int n = s.size();
        int result = 0;
        while (right < n) {
            char c = s[right];
            while (dict.count(c)) {
                // left keep going
                dict.erase(s[left++]);
            }
            dict.insert(c);

            // calculate the length
            result = max(right - left + 1, result);
            right++;
        }
        return result;
    }
};