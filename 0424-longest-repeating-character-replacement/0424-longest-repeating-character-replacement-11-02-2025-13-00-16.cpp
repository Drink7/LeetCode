class Solution {
public:
    int characterReplacement(string s, int k) {
        // TC: O(n)
        // SC: O(n)
        unordered_map<char, int> dict;
        int left = 0, right = 0;
        int n = s.size();
        int maxSize = 0;
        int maxFreq = 0;
        while (right < n) {
            dict[s[right]]++;
            maxFreq = max(maxFreq, dict[s[right]]);
            if (right - left + 1 - maxFreq > k) {
                // not valid
                dict[s[left]]--;
                left++;
            }
            maxSize = max(maxSize, right - left + 1);
            right++;
        }
        return maxSize;
    }
};