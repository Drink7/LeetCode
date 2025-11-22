class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        while (n) {
            result++;
            n = n & (n - 1);
        }
        return result;
    }
};