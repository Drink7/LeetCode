class Solution {
public:
    int findComplement(int num) {
        // set bit mask = 1111111111111111
        // use XOR to original num
        // TC: O(1)
        // SC: O(1)
        // find leading one
        int totalBit = 0;
        int tmp = num;
        while (tmp) {
            tmp = tmp >> 1;
            totalBit++;
        }

        for (int i = 0; i < totalBit; i++) {
            num = num ^ (1 << i);
        }

        return num;
    }
};