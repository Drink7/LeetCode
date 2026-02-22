class Solution {
public:
    int binaryGap(int n) {
        // two pointer or bit shift
        // bit shift: 
        // X: 32 bits
        // O: while (cur)
        // if cur & 1 == 1, compare to ans, then start to next count 
        // TC: O(1)
        // SC: O(1)
        int ans = 0;
        int cnt = 0;
        bool isValid = false;
        while (n) {
            if (n & 1) {
                isValid = true;
                ans = max(ans, cnt);
                cnt = 0;
            }
            if (isValid) {
                cnt++;
            }
            n = n >> 1;
        }
        return ans;
    }
};