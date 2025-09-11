class Solution {
public:
    int countSubstrings(string s) {
        // center expand
        // TC: O(n^2)
        // SC: O(1)
        int cnt = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            // odd
            int left = i;
            int right = i;
            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                }
                cnt++;
                left--;
                right++;
            }

            // even
            left = i;
            right = i + 1;
            while (left >= 0 && right < n) {
                if (s[left] != s[right]) {
                    break;
                }
                cnt++;
                left--;
                right++;
            }
        }
        return cnt;
    }
};