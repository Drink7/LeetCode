class Solution {
public:
    int hammingWeight(int n) {
        // & last bit until n == 0
        // 1011 & 1010
        // --> 1, 1010
        // 1010 & 1001
        // --> 2, 1000
        // 1000 & 0111
        // --> 3, 0000
        // TC: O(n)
        // SC: O(1)
        /*
        int result = 0;
        while (n != 0) {
            n = n & (n - 1);
            result++;
        }
        return result;
        */

        // lookup table
        // TC: O(256)
        // SC: O(1)
        vector<int> table(256, 0);
        lookupTable(table);
        return (table[n & 0xff] +
            table[(n >> 8) & 0xff] +
            table[(n >> 16) & 0xff] +
            table[(n >> 24) & 0xff]);
    }

    void lookupTable(vector<int>& table) {
        for (int i = 0; i < 256; i++) {
            table[i] = (i & 1) + table[i >> 1];
        }
    }
};