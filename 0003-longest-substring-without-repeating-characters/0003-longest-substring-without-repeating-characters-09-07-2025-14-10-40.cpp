class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // longest substring -> sliding window
        // hash table -> unordered_set
        // TC: O(n)
        // SC: O(n)
        unordered_set<char> dict;
        int left = 0, right = 0;
        int n = s.size();
        int result = 0;
        while (right < n) {
            while (left < right && dict.count(s[right]) > 0) {
                dict.erase(s[left]);
                left++;
            }

            dict.insert(s[right]);
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};