class Solution {
public:
    int minOperations(int n) {
        // TC: O(logn)
        // SC: O(1)
        int count = 0;
        while (n > 0) {
            int i = log2(n);
            int prev = pow(2, i);
            int next = pow(2, i + 1);
            
            int prevDiff = n - prev;
            int nextDiff = next - n;
            if (prevDiff > nextDiff) {
                n = nextDiff;
            } else {
                n = prevDiff;
            }
            count++;
        }
        return count;
    }
};