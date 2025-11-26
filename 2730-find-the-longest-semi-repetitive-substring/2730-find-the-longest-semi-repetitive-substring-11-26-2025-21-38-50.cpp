class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        // longest substring -> sliding window
        // right keep going
        // left?
        // at most one adjacent
        // check right and right - 1 is right > 0, only once
        // TC: O(n)
        // SC: O(1)
        int n = s.size();
        int left = 0, right = 0;
        int result = 0;
        int isSame = 0;
        while (right < n) {
            if (right > 0 && s[right] == s[right - 1]) {
                isSame++;
            }

            while (isSame > 1) {
                if (s[left] == s[left + 1]) {
                    isSame--;
                }
                left++;
            }
            result = max(result, right - left + 1);
            right++;
        }
        return result;
    }
};