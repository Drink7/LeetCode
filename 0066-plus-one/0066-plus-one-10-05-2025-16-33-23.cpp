class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        // add from the end
        // TC: O(n)
        // SC: O(1)
        vector<int> result;
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int sum = carry + digits[i];
            if (i == digits.size() - 1) {
                sum += 1;
            }
            carry = sum / 10;
            result.push_back(sum % 10);
        }

        if (carry > 0) {
            result.push_back(1);
        }

        reverse(result.begin(), result.end());
        return result;
    }
};