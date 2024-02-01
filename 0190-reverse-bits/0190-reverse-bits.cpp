class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // traverse 32 times
        // TC: O(1)
        // SC: O(1)
        int result = 0;
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result = result | (n & 1);
            n = n >> 1;
        }
        return result;
    }
};