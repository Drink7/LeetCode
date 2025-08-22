class Solution {
public:
    int myAtoi(string s) {
        // ignore 1st space
        // check positive or not, default is positive
        // TC: O(n)
        // SC: O(n)
        int index = 0;
        int n = s.size();
        while (s[index] == ' ') {
            index++;
        }

        int sign = 1;
        if (index < n && (s[index] == '-' || s[index] == '+')) {
            if (s[index] == '-') {
                sign = -1;
            }
            index++;
        }

        long result = 0;
        while (index < n && isdigit(s[index])) {
            result = result * 10;
            result += s[index] - '0';
            if (sign * result > INT_MAX) {
                return INT_MAX;
            }

            if (sign * result < INT_MIN) {
                return INT_MIN;
            }
            index++;
        }
        return sign * result;
    }
};