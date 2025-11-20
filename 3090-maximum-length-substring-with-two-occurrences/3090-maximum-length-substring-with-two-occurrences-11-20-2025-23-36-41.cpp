class Solution {
public:
    int maximumLengthSubstring(string s) {
        // hash map to store freq
        // sliding window to check
        // if char freq > 2
        // move left
        // calculate right - left + 1
        // TC: O(n)
        // SC: O(n)
        int left = 0, right = 0;
        int n = s.size();
        unordered_map<char, int> freq;
        int maxLen = 0;
        while (right < n) {
            freq[s[right]]++;
            while (freq[s[right]] > 2) {
                freq[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};