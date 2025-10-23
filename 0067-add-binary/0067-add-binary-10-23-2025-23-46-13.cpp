class Solution {
public:
    string addBinary(string a, string b) {
        // 11
        //  1
        //100
        // while (i1 >= 0 || i2 >= 0 || carry)
        // push_back then reverse
        // TC: O(m + n)
        // SC: O(max(m.size(), n.size()))
        // i1 -> -1, i2 -> -1
        // aBit = 0, bBit = 0, sum = 1
        // carry = 0
        // 001
        int i1 = a.size() - 1;
        int i2 = b.size() - 1;
        int carry = 0;
        string result = "";
        while (i1 >= 0 || i2 >= 0 || carry) {
            int aBit = (i1 >= 0) ? a[i1--] - '0' : 0; 
            int bBit = (i2 >= 0) ? b[i2--] - '0' : 0; 
            int sum = aBit + bBit + carry;
            carry = sum / 2;
            result += (sum % 2) + '0';
        }
        reverse(result.begin(), result.end());
        return result;
    }
};