class Solution {
public:
    int getSum(int a, int b) {
        // XOR->sum without carry bit
        // AND -> only carry bit
        // End when carry bit is 0
        // b is the carry
        // TC: O(32)
        // SC: O(1)
        while (b) {
            int sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return a;
    }
};