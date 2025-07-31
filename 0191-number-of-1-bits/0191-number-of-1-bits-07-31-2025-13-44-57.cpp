class Solution {
public:
    int hammingWeight(int n) {
        // & last bit until n == 0
        // 1011 & 1010
        // --> 1, 1010
        // 1010 & 1001
        // --> 2, 1000
        // 1000 & 0111
        // --> 3, 0000
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        while (n != 0) {
            n = n & (n - 1);
            result++;
        }
        return result;
    }
};