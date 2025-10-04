class Solution {
public:
    int getSum(int a, int b) {
        // a || b || carry
        // sum = a ^ b ^ carry
        // carry = l1 & l2 & carry
        // TC: O(m + n)
        // SC: O(1)
        int carry = 0;
        while (a && b) {
            int sum = a ^ b;
            int carry = (a & b) << 1;
            a = sum | carry;
            b = sum & carry;
        }
        return a | b;
    }
};