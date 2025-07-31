class Solution {
public:
    int hammingWeight(int n) {
        // & last bit until n == 0
        // TC: O(n)
        // SC: O(1)
        int result = 0;
        while (n != 0) {
            if (n & 1) {
                result++;
            }
            n = n >> 1;
        }
        return result;
    }
};