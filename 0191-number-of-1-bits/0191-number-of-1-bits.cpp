class Solution {
public:
    int hammingWeight(uint32_t n) {
        // use n & n - 1 skills
        // TC: O(n)
        // SC: O(1)
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
};