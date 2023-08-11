class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Two pointer with sliding window  + hash table set
        // TC; O(n), n is the string length
        // SC: O(n)
        int n = s.size();
        int left = 0;
        int right = 0;
        int result = 0;
        unordered_set<char> dict;
        while (right < n) {
            char rightChar = s[right];
            while (dict.count(rightChar) > 0) {
                dict.erase(s[left]);
                left++;
            }
            result = max(result, right - left + 1);
            dict.insert(s[right]);
            right++;
        }
        return result;
    }
};