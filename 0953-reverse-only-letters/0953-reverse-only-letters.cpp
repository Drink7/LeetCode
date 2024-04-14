class Solution {
public:
    string reverseOnlyLetters(string s) {
        // two pointer to reverse
        // TC: O(n)
        // SC: O(1)
        int left = 0;
        int right = s.size() - 1;
        while (left < right) {
            while (left < right && !isalpha(s[left])) {
                left++;
            }

            while (left < right && !isalpha(s[right])) {
                right--;
            }

            if (left < right) {
                swap(s[left], s[right]);
            }
            left++;
            right--;
        }
        return s;
    }
};