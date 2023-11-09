class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window + hashset
        // TC: O(n)
        // SC: O(n)
        unordered_set<char> dict;
        int left = 0;
        int right = 0;
        int n = s.size();
        int result = 0;
        while (right < n) {
            if (dict.count(s[right]) == 0) {
                dict.insert(s[right]);
                result = max(result, right - left + 1);
                right++;
            } else {
                while (dict.count(s[right])) {
                    dict.erase(s[left]);
                    left++;
                }
            }
        }
        return result;
    }
};