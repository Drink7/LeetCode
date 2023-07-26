class Solution {
public:
    int hammingWeight(uint32_t n) {
        // use a uint32_t one to & n and find the number of 1
        // TC: O(1)
        // SC: O(1)
        int cnt = 0;
        for (int i = 0; i < 32; i++) {
            if (n & 1) {
                cnt++;
            }
            n = n >> 1;
        }
        return cnt;
    }
};