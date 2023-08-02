class Solution {
public:
    int arrangeCoins(int n) {
        // 1 + 2 + 3 + ... + m <= n
        // TC: O(logn)
        // SC: O(1)
        int left = 1;
        int right = n;
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long sum = (1 + mid) * mid / 2;

            if (sum <= n) {
                if ((1 + 1 + mid) * (1 + mid) / 2 > n) {
                    return mid;
                } else {
                    left = mid + 1;
                }
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};