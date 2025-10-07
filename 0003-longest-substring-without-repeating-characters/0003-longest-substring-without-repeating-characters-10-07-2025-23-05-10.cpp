class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // substring -> dp or sliding window
        // TC: O(n)
        // SC: O(n)
        unordered_set<char> dict;
        int left = 0;
        int right = 0;
        int n = s.size();
        int len = 0;
        while (right < n) {
            char rightC = s[right];
            while (left < right && dict.count(rightC) > 0) {
                dict.erase(s[left]);
                left++;
            }
            dict.insert(rightC);
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};