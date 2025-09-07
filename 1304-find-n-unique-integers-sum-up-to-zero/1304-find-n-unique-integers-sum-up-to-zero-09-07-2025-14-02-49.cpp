class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result;
        int base = 0;

        if (n % 2 == 1) {
            // odd, a zero is placed
            result.push_back(0);
            n = n - 1;
        }

        // then find even numbers of ans
        int left = -1, right = 1;
        while (n > 0) {
            result.push_back(left);
            result.push_back(right);
            left--;
            right++;
            n -= 2;
        }
        return result;
    }
};