class Solution {
public:
    int hammingWeight(uint32_t n) {
        // use n & n-1 skills
        // TC: O(1)
        // SC: O(1)
        int count = 0;
        while (n != 0) {
            count++;
            n = n & (n - 1);
        }
        return count;
    }
};