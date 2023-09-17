class Solution {
public:
    int numberOfSteps(int num) {
        // Brute Force
        // TC: O(logn)
        // SC: O(1)
        int cnt = 0;
        while (num != 0) {
            if (num & 1) {
            //if (num % 2) {
                //num -= 1;
                num = num ^ 1;
            } else {
                num = num >> 1;
            }
            cnt++;
        }
        return cnt;
    }
};