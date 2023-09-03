class Solution {
public:
    string addBinary(string a, string b) {
        // traverse each bit of a and b
        // return the answer
        // carry = (bit_a + bit_b) / 2;
        // sum = (carry + (bit_a + bit_b)) % 2;
        // TC: O(m + n)
        // SC: O(m)
        int m = a.size() - 1;
        int n = b.size() - 1;
        string result = "";
        int carry = 0;
        int sum = 0;

        while (m >= 0 || n >= 0) {
            int bitA = (m >= 0) ? a[m--] - '0': 0;
            int bitB = (n >= 0) ? b[n--] - '0': 0;
            sum = (carry + bitA + bitB) % 2;
            carry = (carry + bitA + bitB) / 2;
            result += to_string(sum);
        }

        if (carry == 1) {
            result += "1";
        }

        reverse(result.begin(), result.end());
        return result;
    }
};