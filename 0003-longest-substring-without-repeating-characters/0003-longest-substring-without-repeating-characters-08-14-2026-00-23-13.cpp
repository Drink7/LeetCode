class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // left and right, right keep moving, if the char exist in the set, check the answer and then move right
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> charSet;
        int length = 0;
        while (right < n) {
            while (charSet[s[right]] > 0) {
                charSet[s[left]]--;
                left++;
            }

            charSet[s[right]]++;
            length = max(length, right - left + 1);
            right++;
        }
        return length;

        // abcabcbb
    }
};