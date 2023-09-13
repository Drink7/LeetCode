class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        // find the last same bit from left
        // TC : O(n)
        // SC : O(1)
        int count = 0;
        while (left != right) {
            left = left >> 1;
            right = right >> 1;
            count++;
        }
        return left << count;
    }
};