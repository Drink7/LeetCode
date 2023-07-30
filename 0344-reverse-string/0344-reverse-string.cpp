class Solution {
public:
    void reverseString(vector<char>& s) {
        // Two pointer
        // TC: O(n)
        // SC: O(1)
        int right = s.size() - 1;
        int left = 0;
        while (left <= right) {
            swap(s[left], s[right]);
            right--;
            left++;
        }
    }
};