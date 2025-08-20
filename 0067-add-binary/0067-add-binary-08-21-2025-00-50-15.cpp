class Solution {
public:
    string addBinary(string a, string b) {
        // TC: O(m + n)
        // SC: O(1)
        int indexA = a.size() - 1;
        int indexB = b.size() - 1;
        int carry = 0;
        string result = "";
        while (indexA >= 0 || indexB >= 0 || carry > 0) {
            int intA = indexA >= 0? a[indexA] - '0' : 0;
            int intB = indexB >= 0? b[indexB] - '0' : 0;
            int sum = intA + intB + carry;

            result += to_string(sum % 2);

            carry = sum / 2;
            indexA--;
            indexB--;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};