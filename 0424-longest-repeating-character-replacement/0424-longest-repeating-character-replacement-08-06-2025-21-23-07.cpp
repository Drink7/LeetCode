class Solution {
public:
    int characterReplacement(string s, int k) {
        // longest substring -> sliding window
        // right - left + 1 - k > s[right] cnt --> need to move left
        // maxFreq
        // TC: O(n)
        // SC: O(1)
        int n = s.size();
        int left = 0, right = 0;
        int charArr[26] = {0};
        int result = 0;
        int maxFreq = 0;
        while (right < n) {
            charArr[s[right] - 'A']++;
            maxFreq = max(maxFreq, charArr[s[right] - 'A']);
            while (right - left + 1 - k > maxFreq) {
                charArr[s[left] - 'A']--;
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};