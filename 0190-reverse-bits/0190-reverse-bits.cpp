class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // traverse 32 times
        // TC: O(1)
        // SC: O(1)
        int result = 0;
        int carry = 0;
        for (int i = 0; i < 32; i++) {
            result = result | carry;
            if (n & 1 == 1) {
                carry = 1;
            } else {
                carry = 0;
            }
            n = n >> 1;
            result = result << 1;
        }
        result = result | carry;
        return result;
    }
};