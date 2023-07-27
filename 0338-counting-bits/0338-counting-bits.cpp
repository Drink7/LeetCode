class Solution {
public:
    vector<int> countBits(int n) {
        // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
        // 0 1 1 2 1 2 2 3 1 2 2  3  2  3  3  4  1
        // >> 1: right shift 1 is to divide by 2
        // dynamic programming
        // TC: O(nlogn)
        // SC: O(1)
        vector<int> result;
        for (int i = 0; i <= n; i++) {
            int sum = 0;
            int num = i;
            while (num != 0) {
                sum += num % 2;
                num = num / 2;
            }
            result.push_back(sum);
        }
        return result;
    }
};