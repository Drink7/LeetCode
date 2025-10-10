class Solution {
public:
    int minFlips(int a, int b, int c) {
        /*
        // a XOR b find the diff bit between a & b
        // result compare with c
        // if result bit 0, check the bit is the same as c, not the same, ++
        // if result bit is 1 and c is 0, not the same, ++
        // TC: O(1)
        // SC: O(1)
        int result = a ^ b;
        int cnt = 0;
        while (result) {
            int resultLSB = result & 1;
            int cLSB = c & 1;
            if (resultLSB == 0 && (a & 1 != cLSB)) {
                cnt++;
            }

            if (resultLSB == 1 && cLSB) {
                cnt++;
            }

            a = a >> 1;
            result = result >> 1;
            c = c >> 1;
        }
        return cnt;
        */
        // brute force LSB of a, b, c
        int cnt = 0;
        while (a || b || c) {
            int aLSB = a & 1;
            int bLSB = b & 1;
            int cLSB = c & 1;

            int result = aLSB | bLSB;
            if (result == 0 && cLSB == 1) {
                cnt++;
            } else if (result == 1 && cLSB == 0) {
                if (aLSB == 1 && bLSB == 1) {
                    cnt += 2;
                } else {
                    cnt++;
                }
            }
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return cnt;
    }
};