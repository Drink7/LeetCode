class Solution {
public:
    int hammingWeight(uint32_t n) {
        /*
        // Shift bit
        // TC: O(1)
        // SC: O(1)
        // while loop and check the lsb
        int cnt = 0;
        while (n) {
            if (n & 1) {
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
        */
        // Special (n & n - 1)
        // TC: O(1)
        // SC: O(1)
        int cnt = 0;
        while (n) {
            n = n & (n - 1);
            cnt++;
        }
        return cnt;
    }
};