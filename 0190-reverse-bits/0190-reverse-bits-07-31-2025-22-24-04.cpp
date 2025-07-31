class Solution {
public:
    int reverseBits(int n) {
        // result <<
        // n >>
        // TC: O(32)
        // SC: O(1)
        int result = 0;
        int cnt = 31;
        while (cnt > 0) {
            if (n & 1) {
                result |= 1;
            }
            n = n >> 1;
            result = result << 1;
            cnt--;
        }
        return result;
    }
};