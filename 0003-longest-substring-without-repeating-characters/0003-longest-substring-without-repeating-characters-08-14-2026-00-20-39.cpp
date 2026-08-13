class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // left and right, right keep moving, if the char exist in the set, check the answer and then move right
        // TC: O(n)
        // SC: O(n)
        int n = s.size();
        int left = 0, right = 0;
        unordered_set<char> charSet;
        int length = 0;
        while (right < n) {
            while (charSet.count(s[right]) > 0) {
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(s[right]);
            length = max(length, right - left + 1);
            right++;
        }
        return length;
    }
};