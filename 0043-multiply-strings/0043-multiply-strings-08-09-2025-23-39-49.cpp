class Solution {
public:
    string multiply(string num1, string num2) {
        // multiply by digits, and store in a string array
        // TC: O(m + n)
        // SC: O(m + n)
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        int m = num1.size();
        int n = num2.size();
        vector<int> strArr(m + n, 0);

        int end = m + n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int digit2 = num2[i] - '0';
            int id = end;
            for (int j = m - 1; j >= 0; j--) {
                int digit1 = num1[j] - '0';
                int sum = strArr[id] + digit2 * digit1;
                strArr[id - 1] += sum / 10;
                strArr[id] = sum % 10;
                id--;
            }
            end--;
        }

        bool isLeadingZero = true;
        string result = "";
        for (auto const& digit : strArr) {
            if (digit == 0 && isLeadingZero) {
                continue;
            }
            isLeadingZero = false;
            result += to_string(digit);
        }
        return result;
    }
};