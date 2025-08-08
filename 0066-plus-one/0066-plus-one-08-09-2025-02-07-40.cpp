class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /*
        // Brute Force (Runtime Error) (runtime error: signed integer overflow)
        // Transform to int, plus 1, then transform back to int array
        // TC: O(n)
        // SC: O(n)
        int n = digits.size();
        long ans = 0;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            ans = ans * 10 + digits[i];
        }
        ans += 1;
        string ansStr = to_string(ans);
        for (int i = 0; i < ansStr.size(); i++) {
            result.push_back(ansStr[i] - '0');
        }
        return result;
        */

        // Calculate using carry bit (Default 1, which means plus one)
        // TC: O(n)
        // SC: O(n)
        vector<int> result(digits.begin(), digits.end());
        int carry = 1;
        int n = result.size();
        for (int i = n - 1; i >= 0; i--) {
            int cur = result[i] + carry;
            carry = cur / 10;
            cur = cur % 10;
            result[i] = cur;
        }
        if (carry == 1) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};