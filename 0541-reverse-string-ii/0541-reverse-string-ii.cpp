class Solution {
public:
    string reverseStr(string s, int k) {
        // TC: O(n)
        // SC: O(1)
        int index = 0;
        int n = s.size();
        while (index < n) {
            int left = index;
            int right = min(left + k - 1, n - 1);
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            index += 2 * k;
        }
        return s;
    }
};