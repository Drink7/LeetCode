class Solution {
public:
    string addBinary(string a, string b) {
        // Use sum and carry bit
        // TC: O(m + n), m is a length, n is b length
        // SC: O(1)
        int carry = 0;
        int sum = 0;
        string newStr = "";

        int m = a.size() - 1;
        int n = b.size() - 1;
        while (m >= 0 || n >= 0) {
            int aBit = m >= 0 ? a[m--] - '0' : 0;
            int bBit = n >= 0 ? b[n--] - '0' : 0;
            sum = (carry + aBit + bBit) % 2;
            carry = (carry + aBit + bBit) / 2;
            newStr += to_string(sum);
        }

        if (carry != 0) {
            newStr += to_string(1);
        }

        reverse(newStr.begin(), newStr.end());

        return newStr;
    }
};