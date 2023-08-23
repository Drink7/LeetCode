class Solution {
public:
    int getSum(int a, int b) {
        // cur bit = XOR
        // carry bit = AND
        // make b as carry
        while (b) {
            // cur bit
            int tmp = a ^ b;
            b = (a & b) << 1;
            a = tmp;
        }
        return a;
    }
};