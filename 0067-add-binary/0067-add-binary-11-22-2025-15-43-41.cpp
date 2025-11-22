class Solution {
public:
    string addBinary(string a, string b) {
        // TC: O(max(m, n))
        // SC: O(1)
        int m = a.size() - 1;
        int n = b.size() - 1;
        int carry = 0;
        string result = "";
        while (m >= 0 || n >= 0 || carry) {
            int a1 = (m >= 0) ? a[m--] - '0' : 0;
            int b1 = (n >= 0) ? b[n--] - '0' : 0;
            int sum = a1 + b1 + carry;
            result += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};