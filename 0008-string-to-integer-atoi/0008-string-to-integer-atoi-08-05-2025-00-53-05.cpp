class Solution {
public:
    int myAtoi(string s) {
        // ignore 1st space
        // check positive or not, default is positive
        // TC: O(n)
        // SC: O(n)
        int index = 0;
        while (s[index] == ' ') {
            index++;
        }
        s = s.substr(index);

        bool isPositive = true;
        if (s[0] == '-') {
            isPositive = false;
            s = s.substr(1);
        } else if (s[0] == '+') {
            s = s.substr(1);
        } else {
            // ignore
        }

        int result = 0;
        bool isSet = false;
        for (int i = 0; i < s.size(); i++) {
            if (!isdigit(s[i])) {
                break;
            }
            int digit = s[i] - '0';
            if (!isPositive) {
                digit = digit * (-1);
            }

            if (result > INT_MAX / 10 ||
                (result == INT_MAX / 10 && digit > INT_MAX % 10)) {
                    cout << result << endl;
                    cout << digit << endl;
                return INT_MAX;
            } else if (result < INT_MIN /10 ||
                (result == INT_MIN / 10 && digit < INT_MIN % 10)) {
                return INT_MIN;
            }

            result = result * 10;
            result += digit;
        }
        return result;
    }
};