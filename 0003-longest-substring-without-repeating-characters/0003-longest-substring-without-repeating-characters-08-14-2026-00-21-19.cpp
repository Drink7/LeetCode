class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window with map
        int left = 0;
        int right = 0;
        int n = s.size();
        int result = 0;
        unordered_map<char, int> charDict;
        while (right < n) {
            while (left < right && charDict[s[right]] > 0) {
                charDict[s[left]]--;
                left++;
            }
            result = max(result, right - left + 1);
            charDict[s[right]]++;
            right++;
        }
        return result;
    }
};