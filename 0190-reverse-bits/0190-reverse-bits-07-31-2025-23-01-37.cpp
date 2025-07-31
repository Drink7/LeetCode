class Solution {
public:
    Solution() {
        if (!table_initialized) {
            initializeLookupTable();
        }
    }
    int reverseBits(int n) {
        /*
        // result <<
        // n >>
        // TC: O(32)
        // SC: O(1)
        int result = 0;
        int cnt = 31;
        for (int i = 0; i < 32; i++) {
            result = result << 1;
            result = result | (n & 1);
            n = n >> 1;
        }
        return result;
        */
        return lookup_table[(n & 0xff)] << 24 |
            lookup_table[(n >> 8) & 0xff] << 16 |
            lookup_table[(n >> 16) & 0xff] << 8 |
            lookup_table[(n >> 24) & 0xff];

    }

private:
    static vector<int> lookup_table;
    static bool table_initialized;

    void initializeLookupTable() {
        lookup_table.resize(256);

        for (int i = 0; i < 256; i++) {
            lookup_table[i] = reverseOperation(i);
        }
        table_initialized = true;
    }

    int reverseOperation(int byte) {
        int result = 0;
        for (int i = 0; i < 8; i++) {
            result <<= 1;
            result = result | (byte & 1);
            byte >>= 1;
        }
        return result;
    }
};

vector<int> Solution::lookup_table;
bool Solution::table_initialized = false;