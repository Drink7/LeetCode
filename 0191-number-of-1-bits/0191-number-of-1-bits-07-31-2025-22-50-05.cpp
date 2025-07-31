class Solution {
public:
    Solution() {
        if (!table_initialized) {
            initializeLookupTable();
        }
    }

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
        return (lookup_table[n & 0xff] +
            lookup_table[(n >> 8) & 0xff] +
            lookup_table[(n >> 16) & 0xff] +
            lookup_table[(n >> 24) & 0xff]);
    }

private:
    static vector<int> lookup_table;
    static bool table_initialized;

    void initializeLookupTable() {
        lookup_table.resize(256);

        for (int i = 0; i < 256; i++) {
            lookup_table[i] = (i & 1) + lookup_table[i >> 1];
        }
        table_initialized = true;
    }
};

vector<int> Solution::lookup_table;
bool Solution::table_initialized = false;