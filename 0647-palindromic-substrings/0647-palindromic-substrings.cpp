class Solution {
public:
    int countSubstrings(string s) {
        // similar to LC. 5, but we count here
        // TC: O(n^2)
        // SC: O(1)
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                result++;
                left--;
                right++;
            }
        }
        return result;
    }
};