class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding windows with unordered_set
        // TC: O(n)
        // SC: O(n)
        unordered_set<char> charSet;
        int left = 0;
        int right = 0;
        int n = s.size();
        int result = 0;
        while (right < n) {
            char rightChar = s[right];
            while (charSet.count(rightChar)) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(rightChar);

            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};