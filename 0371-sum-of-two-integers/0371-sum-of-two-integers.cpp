class Solution {
public:
    int getSum(int a, int b) {
        // TC: O(1)
        // SC: O(1)
        // sum -> XOR, carry -> (AND << 1)
        // a is sum, b is carry
        while (b) {
            int sum = a ^ b;
            b = (a & b) << 1;
            a = sum;
        }
        return a;
    }
};