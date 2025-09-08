class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int left = 1;
        int right = n - 1;
        while (left <= right) {
            if (isNoZero(left) && isNoZero(right)) {
                return {left, right};
            }
            left++;
            right--;
        }
        return {-1, -1};
    }

    bool isNoZero(int n) {
        bool isValid = true;
        while (n) {
            if (n % 10 == 0) {
                return false;
            } else {
                n = n / 10;
            }
        }
        return true;
    }
};