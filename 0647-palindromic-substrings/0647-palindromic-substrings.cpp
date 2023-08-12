class Solution {
public:
    int countSubstrings(string s) {
        // Two pointer, starts at the same point, move right and left pointers backwards
        // TC: O(n^2)
        // SC: O(1)
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }

            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        return count;
    }
};